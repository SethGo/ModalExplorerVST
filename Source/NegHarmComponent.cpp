/*
  ==============================================================================

    NegHarmComponent.cpp
    Created: 21 Feb 2021 1:16:59am
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NegHarmComponent.h"

//==============================================================================
NegHarmComponent::NegHarmComponent(ModalExplorerVSTAudioProcessor& p)
: audioProcessor (p)
{
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("NEG-HRM", juce::NotificationType::dontSendNotification);
    sectionHeading.setLookAndFeel (&blueTextLookAndFeel);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Neg-harm button
    addAndMakeVisible (negHarmBtn);
    negHarmBtn.setClickingTogglesState (true);
    negHarmBtn.setToggleState (false, juce::NotificationType::dontSendNotification);
    negHarmBtn.setButtonText ("off");
    negHarmBtn.setLookAndFeel (&customLookAndFeel);
    negHarmBtn.onClick = [this] { toggleNegHarm(); };
    
    negHarmBtnAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment> (audioProcessor.apvts, "NEG", negHarmBtn);
}

NegHarmComponent::~NegHarmComponent()
{
}

void NegHarmComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour (juce::Colour(123, 234, 243));
    g.drawRoundedRectangle (area.toFloat().reduced(2), 10, 2);
}

void NegHarmComponent::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.33f;
    sectionHeading.setBounds (area.removeFromTop(headingYOffset));
    
    // Neg-harm button
    area.removeFromBottom (getHeight() * 0.33f);
    auto reduceAmountX = getWidth() * 0.18f;
    auto reduceAmountY = getHeight() * 0.03f;
    negHarmBtn.setBounds (area.reduced (reduceAmountX, reduceAmountY));
}

void NegHarmComponent::toggleNegHarm()
{
    negHarmOn = !negHarmOn;
    negHarmBtn.setToggleState (negHarmOn, juce::NotificationType::dontSendNotification);
    if (negHarmOn)
    {
        negHarmBtn.setButtonText ("on");
        negHarmMode = true;
    }
    else
    {
        negHarmBtn.setButtonText ("off");
        negHarmMode = false;
    }
}


