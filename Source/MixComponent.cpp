/*
  ==============================================================================

    MixComponent.cpp
    Created: 21 Feb 2021 12:48:44pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MixComponent.h"

//==============================================================================
MixComponent::MixComponent (ModalExplorerVSTAudioProcessor& p)
: audioProcessor (p)
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("MIX", juce::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    sectionHeading.setLookAndFeel(&blueTextLookAndFeel);
    
    // Mix Sliders for each voice
    addAndMakeVisible (mixSliderS); // Soprano
    mixSliderS.setSliderStyle (juce::Slider::LinearBar);
    mixSliderS.setRange (0.0f, 1.0f, 0.01f);
    mixSliderS.setValue (0.8f);
    mixSliderS.setLookAndFeel (&customLookAndFeel);
    mixSliderS.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    mixSliderSAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "MIXS", mixSliderS);
    
    addAndMakeVisible (mixSliderA); // Alto
    mixSliderA.setSliderStyle (juce::Slider::LinearBar);
    mixSliderA.setRange (0.0f, 1.0f, 0.01f);
    mixSliderA.setValue (0.8f);
    mixSliderA.setLookAndFeel (&customLookAndFeel);
    mixSliderA.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    mixSliderAAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "MIXA", mixSliderA);
    
    addAndMakeVisible (mixSliderT); // Tenor
    mixSliderT.setSliderStyle (juce::Slider::LinearBar);
    mixSliderT.setRange (0.0f, 1.0f, 0.01f);
    mixSliderT.setValue (0.8f);
    mixSliderT.setLookAndFeel (&customLookAndFeel);
    mixSliderT.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    mixSliderTAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "MIXT", mixSliderT);
    
    addAndMakeVisible (mixSliderB); // Bass
    mixSliderB.setSliderStyle (juce::Slider::LinearBar);
    mixSliderB.setRange (0.0f, 1.0f, 0.01f);
    mixSliderB.setValue (0.8f);
    mixSliderB.setLookAndFeel (&customLookAndFeel);
    mixSliderB.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    mixSliderBAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "MIXB", mixSliderB);

}

MixComponent::~MixComponent()
{
}

void MixComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour (juce::Colour(123, 234, 243));
    g.drawRoundedRectangle (area.toFloat().reduced (2), 10, 2);
}

void MixComponent::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.15;
    sectionHeading.setBounds (area.removeFromTop(headingYOffset));
    
    // Mix Sliders
    auto reduceX = getWidth() * 0.05;
    auto reduceY = getHeight() * 0.05;
    auto mixSliderYOffset = (getHeight() - headingYOffset) / 4;
    mixSliderS.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));
    mixSliderA.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));
    mixSliderT.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));
    mixSliderB.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));

}
