/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModalExplorerVSTAudioProcessorEditor::ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible (verticalTitleSection);
    addAndMakeVisible (scaleSection);
    addAndMakeVisible (negHarmSection);
    addAndMakeVisible (rbSection);
    addAndMakeVisible (outputLevelSection);
    addAndMakeVisible (inversionSection);
    addAndMakeVisible (chordSection);
    addAndMakeVisible (mixSection);
    
    setSize (750, 500);
}

ModalExplorerVSTAudioProcessorEditor::~ModalExplorerVSTAudioProcessorEditor()
{
}

//==============================================================================
void ModalExplorerVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
}

void ModalExplorerVSTAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    
    // Vertical title section
    auto scaleSectionLabelXOffset = getWidth() * 0.06;
    verticalTitleSection.setBounds (area.removeFromLeft (scaleSectionLabelXOffset));
    
    // Scale section
    auto scaleSectionYOffset = getHeight() * 0.35;
    auto topRow = area.removeFromTop (scaleSectionYOffset);
    auto scaleSectionXOffset = (getWidth()  - scaleSectionLabelXOffset) * 0.65;
    scaleSection.setBounds (topRow.removeFromLeft (scaleSectionXOffset).removeFromTop (scaleSectionYOffset));
    
    // Neg-harm section
    auto thirdOfRemainingTopRowSpace = (getWidth() - scaleSectionLabelXOffset - scaleSectionXOffset) / 3;
    negHarmSection.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (scaleSectionYOffset));
    
    // RB mode section
    rbSection.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (scaleSectionYOffset));
    
    // Output knob section
    outputLevelSection.setBounds (topRow);
    
    // Inversion section
    auto chordSectionProportionToInvAndMixSections = 0.35;
    auto invSectionXOffset = (getWidth() - scaleSectionLabelXOffset) * chordSectionProportionToInvAndMixSections;
    auto chordSectionXOffset = (getWidth() - scaleSectionLabelXOffset - invSectionXOffset * 2);
    inversionSection.setBounds (area.removeFromLeft (invSectionXOffset));
    
    // Chord display section
    chordSection.setBounds (area.removeFromLeft (chordSectionXOffset));
    
    // Mix section
    mixSection.setBounds (area);
};
