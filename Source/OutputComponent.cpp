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
OutputComponent::OutputComponent (ModalExplorerVSTAudioProcessor& p)
: audioProcessor (p)
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("OUTPUT", juce::NotificationType::dontSendNotification);
    sectionHeading.setLookAndFeel (&blueTextLookAndFeel);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Output knob
    addAndMakeVisible (outputKnob);
    outputKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    outputKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    outputKnob.setLookAndFeel (&knobLookAndFeel);
    
    outputKnobAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "OUT", outputKnob);

}

OutputComponent::~OutputComponent()
{
}

void OutputComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour (juce::Colour(123, 234, 243));
    g.drawRoundedRectangle (area.toFloat().reduced(2), 10, 2);
}

void OutputComponent::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.15;
    sectionHeading.setBounds (area.removeFromTop (headingYOffset));
    
    // Output knob
    area.removeFromBottom (headingYOffset);
    outputKnob.setBounds (area);

}
