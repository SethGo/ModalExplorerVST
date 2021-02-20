/*
  ==============================================================================

    NegHarmSection.cpp
    Created: 16 Feb 2021 4:12:54pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NegHarmSection.h"

//==============================================================================
NegHarmSection::NegHarmSection()
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("NEG-HARM", juce::NotificationType::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Neg-harm button
    addAndMakeVisible (negHarmBtn);
    negHarmBtn.setToggleState (false, juce::NotificationType::dontSendNotification);
    negHarmBtn.setButtonText ("off");
    negHarmBtn.onClick = [this] { toggleNegHarm(); };
}

NegHarmSection::~NegHarmSection()
{
}

void NegHarmSection::paint (juce::Graphics& g)
{

}

void NegHarmSection::resized()
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
