/*
  ==============================================================================

    RbSection.cpp
    Created: 16 Feb 2021 4:13:10pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RbSection.h"

//==============================================================================
RbSection::RbSection()
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("RB MODE", juce::NotificationType::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // RB knob
    addAndMakeVisible (rbKnob);
    rbKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rbKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    rbKnob.setRange (0, 18, 1);
    rbKnob.onValueChange = [this] { changeRbMode(); };
    
    // Mode status display (to be made dynamic eventually)
    addAndMakeVisible (modeDisplay);
    modeDisplay.setText ("off", juce::dontSendNotification);
    modeDisplay.setJustificationType (juce::Justification::centred);
}

RbSection::~RbSection()
{
}

void RbSection::paint (juce::Graphics& g)
{

}

void RbSection::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.33f;
    sectionHeading.setBounds (area.removeFromTop (headingYOffset));

    // Mode status display
    modeDisplay.setBounds (area.removeFromBottom (getHeight() * 0.33f));
    
    // RB knob
    rbKnob.setBounds (area);
}
