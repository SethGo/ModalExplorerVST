/*
  ==============================================================================

    OutputComponent.h
    Created: 21 Feb 2021 12:30:09pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class OutputComponent  : public juce::Component
{
public:
    OutputComponent (ModalExplorerVSTAudioProcessor&);
    ~OutputComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider outputKnob;
    juce::Label sectionHeading;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> outputKnobAttachment;
    
    ModalExplorerVSTAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputComponent)
};
