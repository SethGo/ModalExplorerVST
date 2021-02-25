/*
  ==============================================================================

    InversionComponent.cpp
    Created: 20 Feb 2021 10:42:11pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "InversionComponent.h"

//==============================================================================
InversionComponent::InversionComponent (ModalExplorerVSTAudioProcessor& p)
: audioProcessor (p)
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("INVERSION", juce::dontSendNotification);
    sectionHeading.setLookAndFeel (&blueTextLookAndFeel);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Inversion control knobs
    addAndMakeVisible (invKnobS); // Soprano
    invKnobS.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    invKnobS.setLookAndFeel (&knobLookAndFeel);
    invKnobS.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobS.onValueChange = [this] { changeVoice(3); };
    
    invKnobSAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "INVS", invKnobS);

    addAndMakeVisible (invKnobA); // Alto
    invKnobA.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    invKnobA.setLookAndFeel (&knobLookAndFeel);
    invKnobA.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobA.onValueChange = [this] { changeVoice(2); };
    
    invKnobAAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "INVA", invKnobA);
    
    addAndMakeVisible  (invKnobT); // Tenor
    invKnobT.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    invKnobT.setLookAndFeel (&knobLookAndFeel);
    invKnobT.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobT.onValueChange = [this] { changeVoice(1); };
    
    invKnobTAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "INVT", invKnobT);
    
    addAndMakeVisible (invKnobB); // Bass
    invKnobB.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    invKnobB.setLookAndFeel (&knobLookAndFeel);
    invKnobB.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobB.onValueChange = [this] { changeVoice(0); };
    
    invKnobBAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "INVB", invKnobB);
    
    // Voice function labels
    float font = 20.0f;
    addAndMakeVisible (invLabelS);;
    invLabelS.setLookAndFeel (&customLookAndFeel);
    invLabelS.setFont (font);
    
    addAndMakeVisible (invLabelA);
    invLabelA.setLookAndFeel (&customLookAndFeel);
    invLabelA.setFont (font);
    
    addAndMakeVisible (invLabelT);
    invLabelT.setLookAndFeel (&customLookAndFeel);
    invLabelT.setFont (font);
    
    addAndMakeVisible (invLabelB);
    invLabelB.setLookAndFeel (&customLookAndFeel);
    invLabelB.setFont (font);
    
    changeVoice(0);
}

InversionComponent::~InversionComponent()
{
}

void InversionComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour (juce::Colour(123, 234, 243));
    g.drawRoundedRectangle (area.toFloat().reduced(2), 10, 2);
}

void InversionComponent::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.1;
    sectionHeading.setBounds (area.removeFromTop (headingYOffset));
    
    // Inversion knobs
    auto voiceColumnXOffset = getWidth() * 0.4;
    auto col1 = area.removeFromLeft (voiceColumnXOffset);
    auto voiceYOffset = (getHeight() - headingYOffset) / 4;
    int reducedAmount = 3;
    invKnobS.setBounds (col1.removeFromTop (voiceYOffset).reduced (reducedAmount));
    invKnobA.setBounds (col1.removeFromTop (voiceYOffset).reduced (reducedAmount));
    invKnobT.setBounds (col1.removeFromTop (voiceYOffset).reduced (reducedAmount));
    invKnobB.setBounds (col1.reduced (reducedAmount));

    // Voice function labels
    invLabelS.setBounds (area.removeFromTop (voiceYOffset).removeFromRight (voiceColumnXOffset));
    invLabelA.setBounds (area.removeFromTop (voiceYOffset).removeFromRight (voiceColumnXOffset));
    invLabelT.setBounds (area.removeFromTop (voiceYOffset).removeFromRight (voiceColumnXOffset));
    invLabelB.setBounds (area.removeFromRight (voiceColumnXOffset));
}

void InversionComponent::changeVoice (int voice)
{
    int knobVal;
    std::string str;
    switch (voice) {
        case 0:
            knobVal = (int)invKnobB.getValue();
            voicingArray[0] = knobVal;
            str = (knobVal > 0) ? std::to_string(knobVal) : "off";
            invLabelB.setText (str, juce::NotificationType::dontSendNotification);
            break;
        case 1:
            knobVal = (int)invKnobT.getValue();
            voicingArray[1] = knobVal;
            str = (knobVal > 0) ? std::to_string(knobVal) : "off";
            invLabelT.setText (str, juce::NotificationType::dontSendNotification);
            break;
        case 2:
            knobVal = (int)invKnobA.getValue();
            voicingArray[2] = knobVal;
            str = (knobVal > 0) ? std::to_string(knobVal) : "off";
            invLabelA.setText (str, juce::NotificationType::dontSendNotification);
            break;
        case 3:
            knobVal = (int)invKnobS.getValue();
            voicingArray[3] = knobVal;
            str = (knobVal > 0) ? std::to_string(knobVal) : "off";
            invLabelS.setText (str, juce::NotificationType::dontSendNotification);
            break;
        default:
            break;
    }
}
