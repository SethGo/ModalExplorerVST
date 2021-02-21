/*
  ==============================================================================

    ChordComponent.cpp
    Created: 21 Feb 2021 12:48:23pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ChordComponent.h"

//==============================================================================
ChordComponent::ChordComponent()
{
    // Section heading
    addAndMakeVisible (sectionHeading);
    sectionHeading.setText ("CHORD", juce::dontSendNotification);
    sectionHeading.setJustificationType (juce::Justification::centred);
    
    // Chord notes display
    addAndMakeVisible (noteS); // Soprano
    noteS.setText ("B", juce::dontSendNotification);
    noteS.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (noteA); // Alto
    noteA.setText ("G", juce::dontSendNotification);
    noteA.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (noteT); // Tenor
    noteT.setText ("E", juce::dontSendNotification);
    noteT.setJustificationType (juce::Justification::centred);
    
    addAndMakeVisible (noteB); // Bass
    noteB.setText ("C", juce::dontSendNotification);
    noteB.setJustificationType (juce::Justification::centred);
}

ChordComponent::~ChordComponent()
{
}

void ChordComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
}

void ChordComponent::resized()
{
    auto area = getLocalBounds();
    
    // Heading
    auto headingYOffset = getHeight() * 0.08;
    sectionHeading.setBounds (area.removeFromTop (headingYOffset));
    
    // Chord note display
    auto chordNoteYOffset = (getHeight() - headingYOffset) / 4;
    noteS.setBounds (area.removeFromTop (chordNoteYOffset));
    noteA.setBounds (area.removeFromTop (chordNoteYOffset));
    noteT.setBounds (area.removeFromTop (chordNoteYOffset));
    noteB.setBounds (area);
}