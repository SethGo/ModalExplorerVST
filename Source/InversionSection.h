/*
  ==============================================================================

    InversionSection.h
    Created: 16 Feb 2021 4:13:50pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class InversionSection  : public juce::Component
{
public:
    InversionSection();
    ~InversionSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Slider invKnobS, invKnobA, invKnobT, invKnobB;
    juce::Label invLabelS, invLabelA, invLabelT, invLabelB;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InversionSection)
};
