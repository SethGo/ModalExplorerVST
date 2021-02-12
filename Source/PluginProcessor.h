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

    // 5 Make a control variable for the gui to affect, and processor to read such as..
//    float mGain {0.5}; //
    // Val from keyKnob
    int keyVal = 0;
    
    // Vals from note alteration sliders (0: flat, 1: natual, 2: sharp)
    int noteAltSlider2Val = 1;
    int noteAltSlider3Val = 1;
    int noteAltSlider4Val = 1;
    int noteAltSlider5Val = 1;
    int noteAltSlider6Val = 1;
    int noteAltSlider7Val = 1;
    
    // Negative harmony toggle
//    bool negHarmMode = false;
    
    // Glide slider val
    int glideSliderVal = 0;
    
    // Vals from inversion knobs
    int invKnobSVal = 7;
    int invKnobAVal = 5;
    int invKnobTVal = 3;
    int invKnobBVal = 1;

    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessor)
};
