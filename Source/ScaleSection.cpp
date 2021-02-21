/*
  ==============================================================================

    ScaleSection.cpp
    Created: 16 Feb 2021 4:12:45pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ScaleSection.h"

//==============================================================================
ScaleSection::ScaleSection()
{
    // Roman numeral function labels (to be made dynamic eventually to reflect '#' or 'b')
    addAndMakeVisible (romNum1);
    romNum1.setText ("I", juce::dontSendNotification);
    romNum1.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum2);
    romNum2.setText ("II", juce::dontSendNotification);
    romNum2.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum3);
    romNum3.setText ("III", juce::dontSendNotification);
    romNum3.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum4);
    romNum4.setText ("IV", juce::dontSendNotification);
    romNum4.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum5);
    romNum5.setText ("V", juce::dontSendNotification);
    romNum5.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum6);
    romNum6.setText ("VI", juce::dontSendNotification);
    romNum6.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum7);
    romNum7.setText ("VII", juce::dontSendNotification);
    romNum7.setJustificationType(juce::Justification::centred);
    
    // Key knob
    addAndMakeVisible (keyKnob);
    keyKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    keyKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    keyKnob.onValueChange = [this] { changeKey(); };
    keyKnob.setRange(0, 11, 1);
    
    // Note alteration sliders
    addAndMakeVisible (noteAltSlider2);
    noteAltSlider2.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider2.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider2.setRange (0, 2, 1);
    noteAltSlider2.setValue (1);
    noteAltSlider2.onValueChange = [this] { changeNote(1); }; // scale degree 2 is '1' in the array
    
    addAndMakeVisible (noteAltSlider3);
    noteAltSlider3.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider3.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider3.setRange (0, 2, 1);
    noteAltSlider3.setValue (1);
    noteAltSlider3.onValueChange = [this] { changeNote(2); };
    
    addAndMakeVisible (noteAltSlider4);
    noteAltSlider4.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider4.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider4.setRange (0, 2, 1);
    noteAltSlider4.setValue (1);
    noteAltSlider4.onValueChange = [this] { changeNote(3); };
    
    addAndMakeVisible (noteAltSlider5);
    noteAltSlider5.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider5.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider5.setRange (0, 2, 1);
    noteAltSlider5.setValue (1);
    noteAltSlider5.onValueChange = [this] { changeNote(4); };
    
    addAndMakeVisible (noteAltSlider6);
    noteAltSlider6.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider6.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider6.setRange (0, 2, 1);
    noteAltSlider6.setValue (1);
    noteAltSlider6.onValueChange = [this] { changeNote(5); };
    
    addAndMakeVisible (noteAltSlider7);
    noteAltSlider7.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider7.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider7.setRange (0, 2, 1);
    noteAltSlider7.setValue (1);
    noteAltSlider7.onValueChange = [this] { changeNote(6); };
    
    // Actual note display labels (to be made dynamic eventually)
    addAndMakeVisible (note1);
    note1.setText ("C", juce::dontSendNotification);
    note1.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note2);
    note2.setText ("D", juce::dontSendNotification);
    note2.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note3);
    note3.setText ("E", juce::dontSendNotification);
    note3.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note4);
    note4.setText ("F", juce::dontSendNotification);
    note4.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note5);
    note5.setText ("G", juce::dontSendNotification);
    note5.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note6);
    note6.setText ("A", juce::dontSendNotification);
    note6.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note7);
    note7.setText ("B", juce::dontSendNotification);
    note7.setJustificationType(juce::Justification::centred);
    
    // TODO: Put as much of this code into custom LookAndFeel's as possible
}

ScaleSection::~ScaleSection()
{
}

void ScaleSection::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
}

void ScaleSection::resized()
{
    // The 7 scale functions are split up into 7 columns, each with: a Roman numeral, a gui control object, and a real note.
    auto area = getLocalBounds();
    
    // Note 1
    auto colWidth = getWidth() / 7;
    auto romNumRowSpacing = getHeight() / 4;
    auto sliderRowSpacing = romNumRowSpacing * 2;
    auto col1 = area.removeFromLeft (colWidth);
    romNum1.setBounds (col1.removeFromTop (romNumRowSpacing));
    keyKnob.setBounds (col1.removeFromTop (sliderRowSpacing));
    note1.setBounds (col1);
    
    // Note 2
    auto col2 = area.removeFromLeft (colWidth);
    romNum2.setBounds (col2.removeFromTop (romNumRowSpacing));
    noteAltSlider2.setBounds (col2.removeFromTop (sliderRowSpacing));
    note2.setBounds (col2);
    
    // Note 3
    auto col3 = area.removeFromLeft (colWidth);
    romNum3.setBounds (col3.removeFromTop (romNumRowSpacing));
    noteAltSlider3.setBounds (col3.removeFromTop (sliderRowSpacing));
    note3.setBounds (col3);
    
    // Note 4
    auto col4 = area.removeFromLeft (colWidth);
    romNum4.setBounds (col4.removeFromTop (romNumRowSpacing));
    noteAltSlider4.setBounds (col4.removeFromTop (sliderRowSpacing));
    note4.setBounds (col4);
    
    // Note 5
    auto col5 = area.removeFromLeft (colWidth);
    romNum5.setBounds (col5.removeFromTop (romNumRowSpacing));
    noteAltSlider5.setBounds (col5.removeFromTop (sliderRowSpacing));
    note5.setBounds (col5);
    
    // Note 6
    auto col6 = area.removeFromLeft (colWidth);
    romNum6.setBounds (col6.removeFromTop (romNumRowSpacing));
    noteAltSlider6.setBounds (col6.removeFromTop (sliderRowSpacing));
    note6.setBounds (col6);
    
    // Note 7
    romNum7.setBounds (area.removeFromTop (romNumRowSpacing));
    noteAltSlider7.setBounds (area.removeFromTop (sliderRowSpacing));
    note7.setBounds (area);
}
