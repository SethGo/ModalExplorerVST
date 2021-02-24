/*
  ==============================================================================

    InversionComponent.h
    Created: 20 Feb 2021 10:42:11pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class InversionComponent  : public juce::Component
{
public:
    InversionComponent (ModalExplorerVSTAudioProcessor&);
    ~InversionComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void changeVoice (int voice);
    int voicingArray[4] = { 1, 3, 5, 7 };

private:
    juce::Label sectionHeading;
    juce::Slider invKnobS, invKnobA, invKnobT, invKnobB;
    juce::Label invLabelS, invLabelA, invLabelT, invLabelB;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> invKnobSAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> invKnobAAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> invKnobTAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> invKnobBAttachment;
    
    ModalExplorerVSTAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InversionComponent)
};
