/*
  ==============================================================================

    ChordSection.cpp
    Created: 16 Feb 2021 4:13:59pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ChordSection.h"

//==============================================================================
ChordSection::ChordSection()
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

ChordSection::~ChordSection()
{
}

void ChordSection::paint (juce::Graphics& g)
{
    
}

void ChordSection::resized()
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
