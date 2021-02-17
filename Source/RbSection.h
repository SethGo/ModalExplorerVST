/*
  ==============================================================================

    RbSection.h
    Created: 16 Feb 2021 4:13:10pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RbSection  : public juce::Component
{
public:
    RbSection();
    ~RbSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Slider rbKnob;
    juce::Label modeDisplay;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RbSection)
};
