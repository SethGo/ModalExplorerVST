/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModalExplorerVSTAudioProcessor::ModalExplorerVSTAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvts (*this, nullptr, "Parameters", createParameters())
#endif
{
}

ModalExplorerVSTAudioProcessor::~ModalExplorerVSTAudioProcessor()
{
}

//==============================================================================
const juce::String ModalExplorerVSTAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ModalExplorerVSTAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ModalExplorerVSTAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ModalExplorerVSTAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ModalExplorerVSTAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ModalExplorerVSTAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ModalExplorerVSTAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ModalExplorerVSTAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String ModalExplorerVSTAudioProcessor::getProgramName (int index)
{
    return {};
}

void ModalExplorerVSTAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void ModalExplorerVSTAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ModalExplorerVSTAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ModalExplorerVSTAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void ModalExplorerVSTAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    buffer.clear();
    
    // TODO: Make this run conditionally when user clicks something
    int scale[7];
    int inversion[4];
    float velocities[4];
    getScale (scale);
    getInversion (inversion);
    getVelocities (velocities);

    midiProcessor.process (midiMessages, scale, inversion, velocities);
}

//==============================================================================
bool ModalExplorerVSTAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* ModalExplorerVSTAudioProcessor::createEditor()
{
    return new ModalExplorerVSTAudioProcessorEditor (*this);
}

//==============================================================================
void ModalExplorerVSTAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void ModalExplorerVSTAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ModalExplorerVSTAudioProcessor();
}

juce::AudioProcessorValueTreeState::ParameterLayout ModalExplorerVSTAudioProcessor::createParameters()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    params.push_back (std::make_unique<juce::AudioParameterInt> ("KEY", "Key", 0, 11, 0));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("ALT2", "Alt2", 0, 2, 1));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("ALT3", "Alt3", 0, 2, 1));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("ALT4", "Alt4", 0, 2, 1));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("ALT5", "Alt5", 0, 2, 1));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("ALT6", "Alt6", 0, 2, 1));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("ALT7", "Alt7", 0, 2, 1));
    
    params.push_back (std::make_unique<juce::AudioParameterBool> ("NEG", "Neg", false));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("RB", "Rb", 0, 18, 0));
    params.push_back (std::make_unique<juce::AudioParameterFloat> ("OUT", "Out", 0.0f, 1.0f, 0.9f));
    
    params.push_back (std::make_unique<juce::AudioParameterInt> ("INVS", "InvS", 0, 7, 7));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("INVA", "InvA", 0, 7, 5));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("INVT", "InvT", 0, 7, 3));
    params.push_back (std::make_unique<juce::AudioParameterInt> ("INVB", "InvB", 0, 7, 1));
//
    params.push_back (std::make_unique<juce::AudioParameterFloat> ("MIXS", "MixS", 0.0f, 1.0f, 0.8f));
    params.push_back (std::make_unique<juce::AudioParameterFloat> ("MIXA", "MixA", 0.0f, 1.0f, 0.8f));
    params.push_back (std::make_unique<juce::AudioParameterFloat> ("MIXT", "MixT", 0.0f, 1.0f, 0.8f));
    params.push_back (std::make_unique<juce::AudioParameterFloat> ("MIXB", "MixB", 0.0f, 1.0f, 0.8f));
    
    return { params.begin(), params.end() };
};

void ModalExplorerVSTAudioProcessor::getScale (int scale[])
{
    int key = apvts.getRawParameterValue ("KEY")->load();
    int noteAlt2 = apvts.getRawParameterValue ("ALT2")->load();
    int noteAlt3 = apvts.getRawParameterValue ("ALT3")->load();
    int noteAlt4 = apvts.getRawParameterValue ("ALT4")->load();
    int noteAlt5 = apvts.getRawParameterValue ("ALT5")->load();
    int noteAlt6 = apvts.getRawParameterValue ("ALT6")->load();
    int noteAlt7 = apvts.getRawParameterValue ("ALT7")->load();
    
    int rbMode = apvts.getRawParameterValue("RB")->load();
    int negHarmOn = apvts.getRawParameterValue("NEG")->load();
    
    // Determine alteration array from either RbMode selection or user input
    int alterationArray[7] = { 0, 0, 0, 0, 0, 0, 0 };
    if (rbMode > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            alterationArray[i] = RB_ALTERATION_MATRIX[rbMode - 1][i];
        }
    }
    else
    {
        int rawAlterationArray[7] = { 0, noteAlt2, noteAlt3, noteAlt4, noteAlt5, noteAlt6, noteAlt7 };
        for (int i = 1; i < 7; i++)
        {
            alterationArray[i] = rawAlterationArray[i] - 1;
        }
    }

    // Translate to negative mode if it is turned on
    int base[7];
    if (!negHarmOn)
    {
        for (int i = 0; i < 7; i++)
        {
            base[i] = BASE_SCALE[i];
        }
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            base[i] = NEGATIVE_BASE_SCALE[i];
            alterationArray[i] *= -1;
        }
    }

    // Set scale, integrate key and alteration data
    for (int i = 0; i < 7; i++)
    {
        scale[i] = (base[i] + key + alterationArray[i]) % 12;
    }
}

void ModalExplorerVSTAudioProcessor::getInversion (int inversion[])
{
    int bassVoiceFunction = apvts.getRawParameterValue ("INVB")->load();
    int tenorVoiceFunction = apvts.getRawParameterValue ("INVT")->load();
    int altoVoiceFunction = apvts.getRawParameterValue ("INVA")->load();
    int sopranoVoiceFunction = apvts.getRawParameterValue ("INVS")->load();

    inversion[0] = bassVoiceFunction; // Bass
    inversion[1] = tenorVoiceFunction; // Tenor
    inversion[2] = altoVoiceFunction; // Alto
    inversion[3] = sopranoVoiceFunction; // Soprano
}

void ModalExplorerVSTAudioProcessor::getVelocities (float velocities[])
{
    float bassVelocity = apvts.getRawParameterValue ("MIXB")->load();
    float tenorVelocity = apvts.getRawParameterValue ("MIXT")->load();
    float altoVelocity = apvts.getRawParameterValue ("MIXA")->load();
    float sopranoVelocity = apvts.getRawParameterValue ("MIXS")->load();
    float outputLevel = apvts.getRawParameterValue ("OUT")->load();
    
    velocities[0] = bassVelocity * outputLevel;
    velocities[1] = tenorVelocity * outputLevel;
    velocities[2] = altoVelocity * outputLevel;
    velocities[3] = sopranoVelocity * outputLevel;
}
