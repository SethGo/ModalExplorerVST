/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModalExplorerVSTAudioProcessorEditor::ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor& p)
: AudioProcessorEditor (&p), inversionComponent(p), scaleSelectionComponent(p), negHarmComponent (p), rbComponent(p), outputComponent (p), mixComponent(p), audioProcessor (p)
{
    addAndMakeVisible (inversionComponent);
    addAndMakeVisible (scaleSelectionComponent);
    addAndMakeVisible (negHarmComponent);
    addAndMakeVisible (rbComponent);
    addAndMakeVisible (verticalTitleComponent);
    addAndMakeVisible (outputComponent);
    addAndMakeVisible (mixComponent);
    
    setSize (750, 430);
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
    
    // Vertical title component
    auto scaleComponentLabelXOffset = getWidth() * 0.06;
    verticalTitleComponent.setBounds (area.removeFromLeft (scaleComponentLabelXOffset).reduced (reducedAmount));
    
    // Scale Component
    auto scaleComponentYOffset = getHeight() * 0.45;
    auto topRow = area.removeFromTop (scaleComponentYOffset);
    auto scaleComponentXOffset = (getWidth()  - scaleComponentLabelXOffset) * 0.65;
    scaleSelectionComponent.setBounds (topRow.removeFromLeft (scaleComponentXOffset).removeFromTop (scaleComponentYOffset).reduced (reducedAmount));
    
    // Neg-harm Component
    auto thirdOfRemainingTopRowSpace = (getWidth() - scaleComponentLabelXOffset - scaleComponentXOffset) / 3;
    negHarmComponent.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (scaleComponentYOffset).reduced (reducedAmount));
    
    // RB mode Component
    rbComponent.setBounds (topRow.removeFromLeft (thirdOfRemainingTopRowSpace).removeFromTop (scaleComponentYOffset).reduced (reducedAmount));
    
    // Output knob Component
    outputComponent.setBounds (topRow.reduced (reducedAmount));
    
    // Inversion Component
    auto inversionToMixProportion = 0.3;
    auto invComponentXOffset = (getWidth() - scaleComponentLabelXOffset) * inversionToMixProportion;
    inversionComponent.setBounds (area.removeFromLeft (invComponentXOffset).reduced (reducedAmount));
    
    // Mix Component
    mixComponent.setBounds (area.reduced (reducedAmount));
}
