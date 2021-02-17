/*
  ==============================================================================

    ChordSection.h
    Created: 16 Feb 2021 4:13:59pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ChordSection  : public juce::Component
{
public:
    ChordSection();
    ~ChordSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Label noteS, noteA, noteT, noteB;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChordSection)
};
