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
    // 2 Construct the objects by setting parameters, apply LookAndFeel
    
    // Inversion rotary sliders ...look for some way to do this with a loop
    addAndMakeVisible(inversionRotarySlidersS);
    inversionRotarySlidersS.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    inversionRotarySlidersS.setRange (0, 7, 1);
    inversionRotarySlidersS.setValue (7);
    inversionRotarySlidersS.setTextBoxStyle (juce::Slider::TextBoxRight, false, 30, 20);
    inversionRotarySlidersS.setLookAndFeel (&customLookAndFeelCat);
    
    addAndMakeVisible(inversionRotarySlidersA);
    inversionRotarySlidersA.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    inversionRotarySlidersA.setRange (0, 7, 1);
    inversionRotarySlidersA.setValue (5);
    inversionRotarySlidersA.setTextBoxStyle (juce::Slider::TextBoxRight, false, 30, 20);
    inversionRotarySlidersA.setLookAndFeel (&customLookAndFeelCat);
    
    addAndMakeVisible(inversionRotarySlidersT);
    inversionRotarySlidersT.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    inversionRotarySlidersT.setRange (0, 7, 1);
    inversionRotarySlidersT.setValue (3);
    inversionRotarySlidersT.setTextBoxStyle (juce::Slider::TextBoxRight, false, 30, 20);
    inversionRotarySlidersT.setLookAndFeel (&customLookAndFeelCat);
    
    addAndMakeVisible(inversionRotarySlidersB);
    inversionRotarySlidersB.setSliderStyle (juce::Slider::SliderStyle::Rotary);
    inversionRotarySlidersB.setRange (0, 7, 1);
    inversionRotarySlidersB.setValue (1);
    inversionRotarySlidersB.setTextBoxStyle (juce::Slider::TextBoxRight, false, 30, 20);
    inversionRotarySlidersB.setLookAndFeel (&customLookAndFeelCat);
    
    setSize (1100, 750);
}

ModalExplorerVSTAudioProcessorEditor::~ModalExplorerVSTAudioProcessorEditor()
{
}

//==============================================================================
void ModalExplorerVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(5, 41, 66));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ModalExplorerVSTAudioProcessorEditor::resized()
{
    // Inversion placement variables
    int margin = 50;
    int rotarySize = 115;
    int invVerticalSpacing = 90;
    int invVerticalDisplacment = 275;
    
    // 3 Draw the object
    inversionRotarySlidersS.setBounds(margin, invVerticalDisplacment, rotarySize, rotarySize);
    inversionRotarySlidersA.setBounds(margin, invVerticalDisplacment + invVerticalSpacing, rotarySize, rotarySize);
    inversionRotarySlidersT.setBounds(margin, invVerticalDisplacment + invVerticalSpacing*2, rotarySize, rotarySize);
    inversionRotarySlidersB.setBounds(margin, invVerticalDisplacment + invVerticalSpacing*3, rotarySize, rotarySize);
}
