/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModalExplorerVSTAudioProcessorEditor::ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor& p)
: AudioProcessorEditor (&p), inversionComponent(p), scaleSelectionComponent(p), negHarmComponent (p), rbComponent (p), outputComponent (p), mixComponent(p), audioProcessor (p)
{
    addAndMakeVisible (verticalTitleComponentScale);
    verticalTitleComponentScale.setVerticalTitle ("SCALE");
    addAndMakeVisible (verticalTitleComponentVoicing);
    verticalTitleComponentVoicing.setVerticalTitle ("VOICING");
    
    // Top row
    addAndMakeVisible (scaleSelectionComponent);
    addAndMakeVisible (negHarmComponent);
    addAndMakeVisible (rbComponent);
    
    // Bottom row
    addAndMakeVisible (inversionComponent);
    addAndMakeVisible (outputComponent);
    addAndMakeVisible (mixComponent);
    
    setSize (750, 460);
}

ModalExplorerVSTAudioProcessorEditor::~ModalExplorerVSTAudioProcessorEditor()
{
}

//==============================================================================
void ModalExplorerVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(5, 41, 66));
}

void ModalExplorerVSTAudioProcessorEditor::resized()
{
    int reducedAmount = 2.0f;
    auto area = getLocalBounds();
    
    // Top Row vertical title
    auto topRowYOffset = getHeight() * 0.45;
    auto topRow = area.removeFromTop (topRowYOffset);
    auto verticalTitleXOffset = getWidth() * 0.06;
    verticalTitleComponentScale.setBounds (topRow.removeFromLeft (verticalTitleXOffset).reduced (reducedAmount));
    
    // Scale Component
    auto scaleComponentXOffset = (getWidth()  - verticalTitleXOffset) * 0.65;
    scaleSelectionComponent.setBounds (topRow.removeFromLeft (scaleComponentXOffset).removeFromTop (topRowYOffset).reduced (reducedAmount));
    
    // Neg-harm Component
    auto thirdOfRemainingTopRowSpace = (getWidth() - verticalTitleXOffset - scaleComponentXOffset) / 2;
    negHarmComponent.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (topRowYOffset).reduced (reducedAmount));
    
    // RB mode Component
    rbComponent.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (topRowYOffset).reduced (reducedAmount));
    
    // Bottom row vertical title
    verticalTitleComponentVoicing.setBounds (area.removeFromLeft (verticalTitleXOffset).reduced (reducedAmount));
    
    // Inversion Component
    auto inversionToMixProportion = 0.3;
    auto invComponentXOffset = (getWidth() - verticalTitleXOffset) * inversionToMixProportion;
    inversionComponent.setBounds (area.removeFromLeft (invComponentXOffset).reduced (reducedAmount));
    
    // Output knob Component
    outputComponent.setBounds (area.removeFromRight (thirdOfRemainingTopRowSpace).reduced (reducedAmount));
    
    // Mix Component
    mixComponent.setBounds (area.reduced (reducedAmount));
}
