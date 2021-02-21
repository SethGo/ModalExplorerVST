/*
  ==============================================================================

    NegHarmComponent.h
    Created: 21 Feb 2021 1:16:59am
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class NegHarmComponent  : public juce::Component
{
public:
    NegHarmComponent();
    ~NegHarmComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void toggleNegHarm();
    
    bool negHarmOn = false; // Initialize false
    
private:
    juce::TextButton negHarmBtn;
    juce::Label sectionHeading;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NegHarmComponent)
};
