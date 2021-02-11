/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
// Custom LookAndFeel
class CustomLookAndFeel : public juce::LookAndFeel_V4
{
    public:
    CustomLookAndFeel()
    {
        setColour(juce::Slider::thumbColourId, juce::Colour(224, 114, 82));
        setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(123, 234, 243));
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(224, 114, 82));
    }
};

// Custom LookAndFeel, (for categorical sliders)
class CustomLookAndFeelCat : public CustomLookAndFeel
{
    public:
    CustomLookAndFeelCat()
    {
//        setColour(juce::Slider::thumbColourId, juce::Colour(224, 114, 82));
//        setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(123, 234, 243));
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(123, 234, 243));
    }
};

class ModalExplorerVSTAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor&);
    ~ModalExplorerVSTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // 1 instantiate the object
    
    juce::Slider inversionRotarySlidersS;
    juce::Slider inversionRotarySlidersA;
    juce::Slider inversionRotarySlidersT;
    juce::Slider inversionRotarySlidersB;
    
    CustomLookAndFeel customLookAndFeel;
    CustomLookAndFeelCat customLookAndFeelCat;
    
    ModalExplorerVSTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessorEditor)
};
