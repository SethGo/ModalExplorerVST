/*
  ==============================================================================

    VerticalTitleSection.h
    Created: 16 Feb 2021 6:51:10pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class VerticalTitleSection  : public juce::Component
{
public:
    VerticalTitleSection();
    ~VerticalTitleSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VerticalTitleSection)
};
