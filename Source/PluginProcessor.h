/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class ModalExplorerVSTAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    ModalExplorerVSTAudioProcessor();
    ~ModalExplorerVSTAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // Key knob value
    int keyVal;
    
    // Note alteration slider values (0: flat, 1: natual, 2: sharp)
    int noteAltSliderVal2;
    int noteAltSliderVal3;
    int noteAltSliderVal4;
    int noteAltSliderVal5;
    int noteAltSliderVal6;
    int noteAltSliderVal7;
    
    // Negative harmony toggle
    bool negHarmMode = false;
    
    // RB mode values
    int rbModeVal;
    
    // Glide slider values
    float glideSliderVal;
    
    // Inversion knob values
    int invKnobValS;
    int invKnobValA;
    int invKnobValT;
    int invKnobValB;
    
    // Osciallator select combo box values
    int oscSelectValS;
    int oscSelectValA;
    int oscSelectValT;
    int oscSelectValB;
    
    // Oscillator mix bars (need conversion to db)
    float oscMixValS;
    float oscMixValA;
    float oscMixValT;
    float oscMixValB;
    
    // Filter ADSR values
    float filterAVal;
    float filterDVal;
    float filterSVal;
    float filterRVal;
    
    // Amp ADSR values
    float ampAVal;
    float ampDVal;
    float ampSVal;
    float ampRVal;
    
    // Cutoff, res, output
    float cutoffVal;
    float resVal;
    float outputVal;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessor)
};
