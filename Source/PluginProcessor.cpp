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
    
    int scale[7];
    deriveScale(scale);
    int inversion[4];
    deriveInversion(inversion);

    midiProcessor.process (midiMessages, scale, inversion);
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
    
    params.push_back(std::make_unique<juce::AudioParameterInt>("KEY", "Key", 0, 11, 0));
    params.push_back(std::make_unique<juce::AudioParameterInt>("ALT2", "Alt2", 0, 2, 1));
    params.push_back(std::make_unique<juce::AudioParameterInt>("ALT3", "Alt3", 0, 2, 1));
    params.push_back(std::make_unique<juce::AudioParameterInt>("ALT4", "Alt4", 0, 2, 1));
    params.push_back(std::make_unique<juce::AudioParameterInt>("ALT5", "Alt5", 0, 2, 1));
    params.push_back(std::make_unique<juce::AudioParameterInt>("ALT6", "Alt6", 0, 2, 1));
    params.push_back(std::make_unique<juce::AudioParameterInt>("ALT7", "Alt7", 0, 2, 1));
    
    return { params.begin(), params.end() };
};

void ModalExplorerVSTAudioProcessor::deriveScale(int scale[])
{
    int key = apvts.getRawParameterValue ("KEY")->load();
    int noteAlt2 = apvts.getRawParameterValue ("ALT2")->load();
    int noteAlt3 = apvts.getRawParameterValue ("ALT3")->load();
    int noteAlt4 = apvts.getRawParameterValue ("ALT4")->load();
    int noteAlt5 = apvts.getRawParameterValue ("ALT5")->load();
    int noteAlt6 = apvts.getRawParameterValue ("ALT6")->load();
    int noteAlt7 = apvts.getRawParameterValue ("ALT7")->load();
    
    int rawAlterationArray[7] = { 0, noteAlt2, noteAlt3, noteAlt4, noteAlt5, noteAlt6, noteAlt7 };
    int alterationArray[7];
    for (int i = 1; i < 7; i++)
    {
        alterationArray[i] = translateAlterationSliderToChromaticValue (rawAlterationArray[i]);
    }
    
    for (int i = 0; i < 7; i++)
    {
        scale[i] = (BASE_SCALE[i] + key + alterationArray[i]) % 12;
    }
}

void ModalExplorerVSTAudioProcessor::deriveInversion(int inversion[])
{
    // Get inversion data here
}

int ModalExplorerVSTAudioProcessor::translateAlterationSliderToChromaticValue(int alterationSliderValue)
{
    int chromaticValue;
    switch (alterationSliderValue) {
        case 0: // Flat
            chromaticValue = -1;
            break;
        case 1: // Natural
            chromaticValue = 0;
            break;
        case 2: // Sharp
            chromaticValue = 1;
            break;
        default:
            break;
    }
    return chromaticValue;
}
