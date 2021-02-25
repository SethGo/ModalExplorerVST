/*
  ==============================================================================

    MixComponent.h
    Created: 21 Feb 2021 12:48:44pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "LooksAndFeels.h"

//==============================================================================
/*
*/
class MixComponent  : public juce::Component
{
public:
    MixComponent (ModalExplorerVSTAudioProcessor&);
    ~MixComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Slider mixSliderS, mixSliderA, mixSliderT, mixSliderB;
    CustomLookAndFeel customLookAndFeel;
    BlueTextLookAndFeel blueTextLookAndFeel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixSliderSAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixSliderAAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixSliderTAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixSliderBAttachment;
    
    ModalExplorerVSTAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixComponent)
};
