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
    // 2 Construct the objects by setting parameters
    
    // 11 Add listener to the object such as...
    
    
    // Key knob
    addAndMakeVisible(keyKnob);
    keyKnob.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    keyKnob.setRange (0, 11, 1);
    keyKnob.setValue (0);
    keyKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    keyKnob.setLookAndFeel (&knobLookAndFeel);
    keyKnob.addListener(this);
    
    // Note alteration sliders
    addAndMakeVisible(noteAltSlider2);
    noteAltSlider2.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider2.setRange (0, 2, 1);
    noteAltSlider2.setValue (1);
    noteAltSlider2.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider2.setLookAndFeel (&customLookAndFeelCat);
    noteAltSlider2.addListener(this);
    
    addAndMakeVisible(noteAltSlider3);
    noteAltSlider3.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider3.setRange (0, 2, 1);
    noteAltSlider3.setValue (1);
    noteAltSlider3.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider3.setLookAndFeel (&customLookAndFeelCat);
    noteAltSlider3.addListener(this);
    
    addAndMakeVisible(noteAltSlider4);
    noteAltSlider4.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider4.setRange (0, 2, 1);
    noteAltSlider4.setValue (1);
    noteAltSlider4.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider4.setLookAndFeel (&customLookAndFeelCat);
    noteAltSlider4.addListener(this);
    
    addAndMakeVisible(noteAltSlider5);
    noteAltSlider5.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider5.setRange (0, 2, 1);
    noteAltSlider5.setValue (1);
    noteAltSlider5.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider5.setLookAndFeel (&customLookAndFeelCat);
    noteAltSlider5.addListener(this);
    
    addAndMakeVisible(noteAltSlider6);
    noteAltSlider6.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider6.setRange (0, 2, 1);
    noteAltSlider6.setValue (1);
    noteAltSlider6.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider6.setLookAndFeel (&customLookAndFeelCat);
    noteAltSlider6.addListener(this);
    
    addAndMakeVisible(noteAltSlider7);
    noteAltSlider7.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider7.setRange (0, 2, 1);
    noteAltSlider7.setValue (1);
    noteAltSlider7.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider7.setLookAndFeel (&customLookAndFeelCat);
    noteAltSlider7.addListener(this);
    
    // Negative harmony button
    addAndMakeVisible(negHarmBtn);
    negHarmBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
    negHarmBtn.setColour(juce::TextButton::buttonColourId, juce::Colour(5, 41, 66));
    negHarmBtn.setColour(juce::TextButton::buttonOnColourId, juce::Colour(123, 234, 243));
    negHarmBtn.setColour(juce::ComboBox::outlineColourId, juce::Colour(224, 114, 82));
    negHarmBtn.onClick = [this]() { toggleNeg(); };
    
    // RB mode knob
    addAndMakeVisible(rbKnob);
    rbKnob.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    rbKnob.setRange (0, 18, 1);
    rbKnob.setValue (0);
    rbKnob.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 30, 20);
    rbKnob.setLookAndFeel (&knobLookAndFeel);
    rbKnob.addListener(this);
    
    // Glide slider
    addAndMakeVisible(glideSlider);
    glideSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    glideSlider.setRange (0.0f, 1.0f, 0.01f);
    glideSlider.setValue (0.0);
    glideSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 40, 20);
    glideSlider.setLookAndFeel (&customLookAndFeel);
    glideSlider.addListener(this);
    
    // Inversion knobs
    addAndMakeVisible(invKnobS); //Soprano
    invKnobS.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    invKnobS.setRange (0, 7, 1);
    invKnobS.setValue (7);
    invKnobS.setTextBoxStyle (juce::Slider::TextBoxRight, false, 20, 20);
    invKnobS.setLookAndFeel (&knobLookAndFeel);
    invKnobS.addListener(this);
    
    addAndMakeVisible(invKnobA); //Alto
    invKnobA.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    invKnobA.setRange (0, 7, 1);
    invKnobA.setValue (5);
    invKnobA.setTextBoxStyle (juce::Slider::TextBoxRight, false, 20, 20);
    invKnobA.setLookAndFeel (&knobLookAndFeel);
    invKnobA.addListener(this);
    
    addAndMakeVisible(invKnobT); //Tenor
    invKnobT.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    invKnobT.setRange (0, 7, 1);
    invKnobT.setValue (3);
    invKnobT.setTextBoxStyle (juce::Slider::TextBoxRight, false, 20, 20);
    invKnobT.setLookAndFeel (&knobLookAndFeel);
    invKnobT.addListener(this);
    
    addAndMakeVisible(invKnobB); //Bass
    invKnobB.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    invKnobB.setRange (0, 7, 1);
    invKnobB.setValue (1);
    invKnobB.setTextBoxStyle (juce::Slider::TextBoxRight, false, 20, 20);
    invKnobB.setLookAndFeel (&knobLookAndFeel);
    invKnobS.addListener(this);
    
    
    
    
    setSize (1100, 750);
}

ModalExplorerVSTAudioProcessorEditor::~ModalExplorerVSTAudioProcessorEditor()
{
}

// Negative harmony toggle function
void ModalExplorerVSTAudioProcessorEditor::toggleNeg()
{
    if (audioProcessor.negHarmMode == false)
    {
        negHarmBtn.setToggleState(true, juce::NotificationType::dontSendNotification);
        audioProcessor.negHarmMode = true;
    }
    else
    {
        negHarmBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
        audioProcessor.negHarmMode = false;
    }
}

//==============================================================================
void ModalExplorerVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(5, 41, 66));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void ModalExplorerVSTAudioProcessorEditor::resized()
{
    // Placement and sizing variables
    int keyKnobSize = 85;
    int keyKnobX = 80;
    int keyKnobY = 160;
    int firstInvKnobY = keyKnobY * 1.5;
    int invKnobSize = 125;
    int invKnobVertSpacing = 100;
    int noteAltsliderWidth = 40;
    int noteAltSliderHeight = 90;
    int noteAltSliderHorizSpacing = 90;
    int firstNoteAltSliderX = keyKnobX + noteAltSliderHorizSpacing + noteAltsliderWidth;
    int noteAltSliderY = keyKnobY - keyKnobSize - 8;
    int negHarmBtnX = firstNoteAltSliderX + noteAltSliderHorizSpacing*6 + 10;
    int negHarmBtnY = noteAltSliderY + 12;
    int rbKnobSize = keyKnobSize;
    int rbKnobX = negHarmBtnX + noteAltSliderHorizSpacing;
    int rbKnobY = keyKnobY - 45;
    int glideSliderX = rbKnobX + noteAltSliderHorizSpacing + 17;
    
    
    // 3 Draw the object with .setBounds()
    keyKnob.setBounds(keyKnobX, keyKnobY - keyKnobSize, keyKnobSize, keyKnobSize);
    
    // Note alteration sliders
    noteAltSlider2.setBounds(firstNoteAltSliderX, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider3.setBounds(firstNoteAltSliderX + noteAltSliderHorizSpacing, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider4.setBounds(firstNoteAltSliderX + noteAltSliderHorizSpacing*2, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider5.setBounds(firstNoteAltSliderX + noteAltSliderHorizSpacing*3, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider6.setBounds(firstNoteAltSliderX + noteAltSliderHorizSpacing*4, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider7.setBounds(firstNoteAltSliderX + noteAltSliderHorizSpacing*5, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    
    // Negative harmony button
    negHarmBtn.setBounds(negHarmBtnX, negHarmBtnY, 60, 60);
    
    // RB mode knob
    rbKnob.setBounds(rbKnobX, rbKnobY-40, rbKnobSize, rbKnobSize);
    
    // Glide slider
    glideSlider.setBounds(glideSliderX, noteAltSliderY, 40, 120);
    
    // Inversion knobs
    invKnobS.setBounds(keyKnobX, firstInvKnobY, invKnobSize, invKnobSize);
    invKnobA.setBounds(keyKnobX, firstInvKnobY + invKnobVertSpacing, invKnobSize, invKnobSize);
    invKnobT.setBounds(keyKnobX, firstInvKnobY + invKnobVertSpacing*2, invKnobSize, invKnobSize);
    invKnobB.setBounds(keyKnobX, firstInvKnobY + invKnobVertSpacing*3, invKnobSize, invKnobSize);
    
    
    
    
}

// 9 Implement gui object listener
void ModalExplorerVSTAudioProcessorEditor::sliderValueChanged (juce::Slider *slider) //
{
    //10 Connect value of gui object to control variable such as...
    // "If the slider whose value was heard to have been changed by the listener is THIS particular slider, then do something with this control variable coming from the audio processor."
    // Key knob
    if (slider == &keyKnob)
    {
        audioProcessor.keyVal = static_cast<int>(keyKnob.getValue());
    }
    
    // Note alteration sliders
    else if (slider == &noteAltSlider2)
    {
        audioProcessor.noteAltSlider2Val = static_cast<int>(noteAltSlider2.getValue());
    }
    else if (slider == &noteAltSlider3)
    {
        audioProcessor.noteAltSlider3Val = static_cast<int>(noteAltSlider3.getValue());
    }
    else if (slider == &noteAltSlider4)
    {
        audioProcessor.noteAltSlider4Val = static_cast<int>(noteAltSlider4.getValue());
    }
    else if (slider == &noteAltSlider5)
    {
        audioProcessor.noteAltSlider5Val = static_cast<int>(noteAltSlider5.getValue());
    }
    else if (slider == &noteAltSlider6)
    {
        audioProcessor.noteAltSlider6Val = static_cast<int>(noteAltSlider6.getValue());
    }
    else if (slider == &noteAltSlider7)
    {
        audioProcessor.noteAltSlider7Val = static_cast<int>(noteAltSlider7.getValue());
    }
    
    // RB knob
    else if (slider == &rbKnob)
    {
        audioProcessor.rbModeVal = static_cast<int>(rbKnob.getValue());
    }
    
    // Glide slider
    else if (slider == &glideSlider)
    {
        audioProcessor.glideSliderVal = glideSlider.getValue();
    }
    
    // Inversion knobs
    else if (slider == &invKnobS)
    {
        audioProcessor.invKnobSVal = static_cast<int>(invKnobS.getValue());
    }
    else if (slider == &invKnobA)
    {
        audioProcessor.invKnobAVal = static_cast<int>(invKnobA.getValue());
    }
    else if (slider == &invKnobT)
    {
        audioProcessor.invKnobTVal = static_cast<int>(invKnobT.getValue());
    }
    else if (slider == &invKnobB)
    {
        audioProcessor.invKnobBVal = static_cast<int>(invKnobB.getValue());
    }
    
}
