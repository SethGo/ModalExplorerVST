/*
  ==============================================================================

    RbComponent.h
    Created: 21 Feb 2021 4:58:42am
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RbComponent  : public juce::Component
{
public:
    RbComponent();
    ~RbComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void changeRbMode();
    
    int rbMode = 0; // Initialize RB mode off

private:
    juce::Label sectionHeading;
    juce::Slider rbKnob;
    juce::Label modeDisplay;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RbComponent)
};
