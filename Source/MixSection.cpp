/*
  ==============================================================================

    MixSection.cpp
    Created: 17 Feb 2021 1:48:23am
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MixSection.h"

//==============================================================================
MixSection::MixSection()
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("MIX", juce::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Mix Sliders for each voice
    addAndMakeVisible (mixSliderS); // Soprano
    mixSliderS.setSliderStyle (juce::Slider::LinearBar);
    mixSliderS.setRange (0.0f, 1.0f, 0.01f);
    mixSliderS.setValue (0.8f);
    mixSliderS.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    addAndMakeVisible (mixSliderA); // Alto
    mixSliderA.setSliderStyle (juce::Slider::LinearBar);
    mixSliderA.setRange (0.0f, 1.0f, 0.01f);
    mixSliderA.setValue (0.8f);
    mixSliderA.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    addAndMakeVisible (mixSliderT); // Tenor
    mixSliderT.setSliderStyle (juce::Slider::LinearBar);
    mixSliderT.setRange (0.0f, 1.0f, 0.01f);
    mixSliderT.setValue (0.8f);
    mixSliderT.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
    
    addAndMakeVisible (mixSliderB); // Bass
    mixSliderB.setSliderStyle (juce::Slider::LinearBar);
    mixSliderB.setRange (0.0f, 1.0f, 0.01f);
    mixSliderB.setValue (0.8f);
    mixSliderB.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 0, 0);
}

MixSection::~MixSection()
{
}

void MixSection::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
}

void MixSection::resized()
{
    auto area = getLocalBounds();
    
    // Section heading
    auto headingYOffset = getHeight() * 0.08;
    sectionHeading.setBounds (area.removeFromTop(headingYOffset));
    
    // Mix Sliders
    auto mixSliderYOffset = (getHeight() - headingYOffset) / 4;
    auto reduceX = getWidth() * 0.05;
    auto reduceY = getWidth() * 0.05;
    mixSliderS.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));
    mixSliderA.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));
    mixSliderT.setBounds (area.removeFromTop (mixSliderYOffset).reduced (reduceX, reduceY));
    mixSliderB.setBounds (area.reduced (reduceX, reduceY));
}
