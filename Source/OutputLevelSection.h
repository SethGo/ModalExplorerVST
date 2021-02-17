/*
  ==============================================================================

    OutputLevelSection.h
    Created: 16 Feb 2021 4:17:42pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class OutputLevelSection  : public juce::Component
{
public:
    OutputLevelSection();
    ~OutputLevelSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider outputKnob;
    juce::Label sectionHeading;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputLevelSection)
};
