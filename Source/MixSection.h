/*
  ==============================================================================

    MixSection.h
    Created: 17 Feb 2021 1:48:23am
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MixSection  : public juce::Component
{
public:
    MixSection();
    ~MixSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Slider mixSliderS, mixSliderA, mixSliderT, mixSliderB;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixSection)
};
