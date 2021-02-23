/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModalExplorerVSTAudioProcessorEditor::ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor& p)
: AudioProcessorEditor (&p), scaleSelectionComponent(p), rbComponent(p), negHarmComponent (p), audioProcessor (p)
{
    addAndMakeVisible (inversionComponent);
    addAndMakeVisible (scaleSelectionComponent);
    addAndMakeVisible (negHarmComponent);
    addAndMakeVisible (rbComponent);
    addAndMakeVisible (verticalTitleComponent);
    addAndMakeVisible (outputComponent);
    addAndMakeVisible (chordComponent);
    addAndMakeVisible (mixComponent);
    
    setSize (750, 500);
}

ModalExplorerVSTAudioProcessorEditor::~ModalExplorerVSTAudioProcessorEditor()
{
}

//==============================================================================
void ModalExplorerVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void ModalExplorerVSTAudioProcessorEditor::resized()
{
    // Change "Section" to "Component"
    auto area = getLocalBounds();
    
    // Vertical title component
    auto scaleComponentLabelXOffset = getWidth() * 0.06;
    verticalTitleComponent.setBounds (area.removeFromLeft (scaleComponentLabelXOffset));
    
    // Scale Component
    auto scaleComponentYOffset = getHeight() * 0.35;
    auto topRow = area.removeFromTop (scaleComponentYOffset);
    auto scaleComponentXOffset = (getWidth()  - scaleComponentLabelXOffset) * 0.65;
    scaleSelectionComponent.setBounds (topRow.removeFromLeft (scaleComponentXOffset).removeFromTop (scaleComponentYOffset));
    
    // Neg-harm Component
    auto thirdOfRemainingTopRowSpace = (getWidth() - scaleComponentLabelXOffset - scaleComponentXOffset) / 3;
    negHarmComponent.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (scaleComponentYOffset));
    
    // RB mode Component
    rbComponent.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (scaleComponentYOffset));
    
    // Output knob Component
    outputComponent.setBounds (topRow);
    
    // Inversion Component
    auto chordComponentProportionToInvAndMixComponents = 0.349;
    auto invComponentXOffset = (getWidth() - scaleComponentLabelXOffset) * chordComponentProportionToInvAndMixComponents;
    inversionComponent.setBounds (area.removeFromLeft (invComponentXOffset));
    
    // Chord display Component
    auto chordComponentXOffset = (getWidth() - scaleComponentLabelXOffset - invComponentXOffset * 2);
    chordComponent.setBounds (area.removeFromLeft (chordComponentXOffset));

    // Mix Component
    mixComponent.setBounds (area);
}
