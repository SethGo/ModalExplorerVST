/*
  ==============================================================================

    MixComponent.h
    Created: 21 Feb 2021 12:48:44pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MixComponent  : public juce::Component
{
public:
    MixComponent();
    ~MixComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Slider mixSliderS, mixSliderA, mixSliderT, mixSliderB;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixComponent)
};
