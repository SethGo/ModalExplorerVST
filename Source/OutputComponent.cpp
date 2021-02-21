/*
  ==============================================================================

    OutputComponent.cpp
    Created: 21 Feb 2021 12:30:09pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OutputComponent.h"

//==============================================================================
OutputComponent::OutputComponent()
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("OUTPUT", juce::NotificationType::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Output knob
    addAndMakeVisible (outputKnob);
    outputKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    outputKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    outputKnob.setRange (0.0f, 1.0f, 0.01f);

}

OutputComponent::~OutputComponent()
{
}

void OutputComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
}

void OutputComponent::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.33f;
    sectionHeading.setBounds (area.removeFromTop (headingYOffset));
    
    // Output knob
    area.removeFromBottom (getHeight() * 0.33f);
    outputKnob.setBounds (area);

}
