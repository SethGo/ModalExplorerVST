/*
  ==============================================================================

    ChordComponent.h
    Created: 21 Feb 2021 12:48:23pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ChordComponent  : public juce::Component
{
public:
    ChordComponent();
    ~ChordComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label sectionHeading;
    juce::Label noteS, noteA, noteT, noteB;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChordComponent)
};
