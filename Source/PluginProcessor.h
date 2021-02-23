/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MidiProcessor.h"

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
    
    void getScale(int scale[]);
    void getInversion(int inversion[]);
    int translateAlterationSliderToChromaticValue(int alterationSliderValue);
    
    juce::AudioProcessorValueTreeState apvts;
    MidiProcessor midiProcessor;

private:
    const int BASE_SCALE[7] = { 0, 2, 4, 5, 7, 9, 11 };
    const int NEGATIVE_BASE_SCALE[7] = { 7, 5, 3, 2, 0, 10, 8 };
    const int RB_ALTERATION_MATRIX[18][7] =
    {
        { 0, -1, 0, 0, 0, -1, 0 },
        { 0, -1, 0, 0, 0, 0, 0 },
        { 0, -1, 0, 0, 0, 1, 0 },
        { 0, -1, 0, 1, 0, -1, 0 },
        { 0, -1, 0, 1, 0, 0, 0 },
        { 0, -1, 0, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, -1, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 1, 0, -1, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 0, 0, -1, 0 },
        { 0, 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 1, 0 },
        { 0, 1, 0, 1, 0, -1, 0 },
        { 0, 1, 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 1, 0 }
    };
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessor)
};
