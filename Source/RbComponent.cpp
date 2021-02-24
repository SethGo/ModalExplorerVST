/*
  ==============================================================================

    RbComponent.cpp
    Created: 21 Feb 2021 4:58:42am
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "RbComponent.h"

//==============================================================================
RbComponent::RbComponent(ModalExplorerVSTAudioProcessor& p)
: audioProcessor (p)
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("RB MODE", juce::NotificationType::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // RB knob
    addAndMakeVisible (rbKnob);
    rbKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rbKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    rbKnob.onValueChange = [this] { changeRbMode(); };
    rbKnobAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "RB", rbKnob);
    
    // Mode status display (to be made dynamic eventually)
    addAndMakeVisible (modeDisplay);
    modeDisplay.setText ("off", juce::dontSendNotification);
    modeDisplay.setJustificationType (juce::Justification::centred);

}

RbComponent::~RbComponent()
{
}

void RbComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
}

void RbComponent::resized()
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

void RbComponent::changeRbMode()
{
    std::string str;
    rbMode = (int)rbKnob.getValue();
    if (rbMode > 0)
    {
        str = std::to_string(rbMode);
    }
    else
    {
        str = "off";
    }
    modeDisplay.setText (str, juce::NotificationType::dontSendNotification);
}
