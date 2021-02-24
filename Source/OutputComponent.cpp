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
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Output knob
    addAndMakeVisible (outputKnob);
    outputKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    outputKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    
    outputKnobAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "OUT", outputKnob);

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
