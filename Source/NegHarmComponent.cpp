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
NegHarmComponent::NegHarmComponent()
{
    
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("NEG-HARM", juce::NotificationType::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Neg-harm button
    addAndMakeVisible (negHarmBtn);
    negHarmBtn.setToggleState (false, juce::NotificationType::dontSendNotification);
    negHarmBtn.setButtonText ("off");
    negHarmBtn.onClick = [this] { toggleNegHarm(); };

}

NegHarmComponent::~NegHarmComponent()
{
}

void NegHarmComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
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
    }
    else
    {
        negHarmBtn.setButtonText ("off");
    }
}
