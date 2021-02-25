/*
  ==============================================================================

    ScaleSelectionComponent.cpp
    Created: 20 Feb 2021 11:35:58pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ScaleSelectionComponent.h"

//==============================================================================
ScaleSelectionComponent::ScaleSelectionComponent (ModalExplorerVSTAudioProcessor& p)
:  audioProcessor (p)
{
    // Roman numeral function labels (to be made dynamic eventually to reflect '#' or 'b')
    float font = 20.0f;
    addAndMakeVisible (romNum1);
    romNum1.setText ("I", juce::dontSendNotification);
    romNum1.setLookAndFeel (&customLookAndFeel);
    romNum1.setFont (font);
    romNum1.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum2);
    romNum2.setText ("II", juce::dontSendNotification);
    romNum2.setLookAndFeel (&customLookAndFeel);
    romNum2.setFont (font);
    romNum2.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum3);
    romNum3.setText ("III", juce::dontSendNotification);
    romNum3.setLookAndFeel (&customLookAndFeel);
    romNum3.setFont (font);
    romNum3.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum4);
    romNum4.setText ("IV", juce::dontSendNotification);
    romNum4.setLookAndFeel (&customLookAndFeel);
    romNum4.setFont (font);
    romNum4.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum5);
    romNum5.setText ("V", juce::dontSendNotification);
    romNum5.setLookAndFeel (&customLookAndFeel);
    romNum5.setFont (font);
    romNum5.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum6);
    romNum6.setText ("VI", juce::dontSendNotification);
    romNum6.setLookAndFeel (&customLookAndFeel);
    romNum6.setFont (font);
    romNum6.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (romNum7);
    romNum7.setText ("VII", juce::dontSendNotification);
    romNum7.setLookAndFeel (&customLookAndFeel);
    romNum7.setFont (font);
    romNum7.setJustificationType(juce::Justification::centred);
    
    // Key knob
    addAndMakeVisible (keyKnob);
    keyKnob.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    keyKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    keyKnob.setLookAndFeel (&knobLookAndFeel);
    keyKnob.onValueChange = [this] { changeNote(0); };
    
    keyKnobAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "KEY", keyKnob);
    
    // Note alteration sliders
    addAndMakeVisible (noteAltSlider2);
    noteAltSlider2.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider2.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider2.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider2.onValueChange = [this] { changeNote(1); };
    
    noteAltSlider2Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT2", noteAltSlider2);
    
    addAndMakeVisible (noteAltSlider3);
    noteAltSlider3.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider3.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider3.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider3.onValueChange = [this] { changeNote(2); };
    
    noteAltSlider3Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT3", noteAltSlider3);
    
    addAndMakeVisible (noteAltSlider4);
    noteAltSlider4.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider4.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider4.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider4.onValueChange = [this] { changeNote(3); };
    
    noteAltSlider4Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT4", noteAltSlider4);
    
    addAndMakeVisible (noteAltSlider5);
    noteAltSlider5.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider5.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider5.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider5.onValueChange = [this] { changeNote(4); };
    
    noteAltSlider5Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT5", noteAltSlider5);
    
    addAndMakeVisible (noteAltSlider6);
    noteAltSlider6.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider6.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider6.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider6.onValueChange = [this] { changeNote(5); };
    
    noteAltSlider6Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT6", noteAltSlider6);
    
    addAndMakeVisible (noteAltSlider7);
    noteAltSlider7.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider7.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider7.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider7.onValueChange = [this] { changeNote(6); };
    
    noteAltSlider7Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT7", noteAltSlider7);
    
    // Actual note display labels (to be made dynamic eventually)
    font = 16.0f;
    addAndMakeVisible (note1);
    note1.setLookAndFeel (&customLookAndFeel);
    note1.setFont (font);
    note1.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note2);
    note2.setLookAndFeel (&customLookAndFeel);
    note2.setFont (font);
    note2.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note3);
    note3.setLookAndFeel (&customLookAndFeel);
    note3.setFont (font);
    note3.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note4);
    note4.setLookAndFeel (&customLookAndFeel);
    note4.setFont (font);
    note4.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note5);
    note5.setLookAndFeel (&customLookAndFeel);
    note5.setFont (font);
    note5.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note6);
    note6.setLookAndFeel (&customLookAndFeel);
    note6.setFont (font);
    note6.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible (note7);
    note7.setLookAndFeel (&customLookAndFeel);
    note7.setFont (font);
    note7.setJustificationType(juce::Justification::centred);
}

ScaleSelectionComponent::~ScaleSelectionComponent()
{
}

void ScaleSelectionComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour (juce::Colour(123, 234, 243));
    g.drawRoundedRectangle (area.toFloat().reduced(2), 10, 2);
    updateScale();
}

void ScaleSelectionComponent::resized()
{
    // The 7 scale functions are split up into 7 columns, each with: a Roman numeral, a gui control object, and a real note.
    auto area = getLocalBounds().reduced(5);
    
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

void ScaleSelectionComponent::updateScale()
{
    int rbMode = audioProcessor.apvts.getRawParameterValue("RB")->load();
    int negHarmOn = audioProcessor.apvts.getRawParameterValue("NEG")->load();
    
    // Determine alteration array from either RbMode selection or user input
    if (rbMode > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            alterationArray[i] = RB_ALTERATION_MATRIX[rbMode - 1][i];
        }
        // Set slider positions
        noteAltSlider2.setValue (RB_ALTERATION_MATRIX[rbMode - 1][1] + 1);
        noteAltSlider3.setValue (RB_ALTERATION_MATRIX[rbMode - 1][2] + 1);
        noteAltSlider4.setValue (RB_ALTERATION_MATRIX[rbMode - 1][3] + 1);
        noteAltSlider5.setValue (RB_ALTERATION_MATRIX[rbMode - 1][4] + 1);
        noteAltSlider6.setValue (RB_ALTERATION_MATRIX[rbMode - 1][5] + 1);
        noteAltSlider7.setValue (RB_ALTERATION_MATRIX[rbMode - 1][6] + 1);
        rbModeWasOn = true;
    }
    
    if (rbMode == 0 && rbModeWasOn)
    {
        // Set slider positions
        noteAltSlider2.setValue (1);
        noteAltSlider3.setValue (1);
        noteAltSlider4.setValue (1);
        noteAltSlider5.setValue (1);
        noteAltSlider6.setValue (1);
        noteAltSlider7.setValue (1);
        
        // Reset alteration array
        for (int i = 0; i < 7; i++)
        {
            alterationArray[i] = 0;
        }
        rbModeWasOn = false;
    }

    // Translate to negative mode if it is turned on
    int base[7];
    if (!negHarmOn)
    {
        for (int i = 0; i < 7; i++)
        {
            base[i] = BASE_SCALE[i];
            finalAlterations[i] = alterationArray[i];
        }
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            base[i] = NEGATIVE_BASE_SCALE[i];
            finalAlterations[i] = alterationArray[i] * -1;
        }
    }

    // Set scale, integrate key and alteration data
    for (int i = 0; i < 7; i++)
    {
        scale[i] = (base[i] + (int)keyKnob.getValue() + finalAlterations[i]) % 12;
    }
    
    note1.setText (noteNames[scale[0]], juce::NotificationType::dontSendNotification);
    note2.setText (noteNames[scale[1]], juce::NotificationType::dontSendNotification);
    note3.setText (noteNames[scale[2]], juce::NotificationType::dontSendNotification);
    note4.setText (noteNames[scale[3]], juce::NotificationType::dontSendNotification);
    note5.setText (noteNames[scale[4]], juce::NotificationType::dontSendNotification);
    note6.setText (noteNames[scale[5]], juce::NotificationType::dontSendNotification);
    note7.setText (noteNames[scale[6]], juce::NotificationType::dontSendNotification);
}

std::string ScaleSelectionComponent::getAccidental (int sliderVal)
{
    // Get accidental from slider val
    std::string prefix;
    switch (sliderVal) {
        case 0: // Flat
            prefix = "b";
            break;
        case 1: // Natural
            prefix = " ";
            break;
        case 2: // Sharp
            prefix = "#";
            break;
        default:
            break;
    }
    return prefix;
}

void ScaleSelectionComponent::changeNote (int scaleDegree)
{
    int val;
    std::string accidental;
    switch (scaleDegree) {
        case 1:
            val = noteAltSlider2.getValue();
            accidental = getAccidental (val);
            romNum2.setText (accidental + "II", juce::dontSendNotification);
            alterationArray[1] = val - 1;
            break;
        case 2:
            val = noteAltSlider3.getValue();
            accidental = getAccidental (val);
            romNum3.setText (accidental + "III", juce::dontSendNotification);
            alterationArray[2] = val - 1;
            break;
        case 3:
            val = noteAltSlider4.getValue();
            accidental = getAccidental (val);
            romNum4.setText (accidental + "IV", juce::dontSendNotification);
            alterationArray[3] = val - 1;
            break;
        case 4:
            val = noteAltSlider5.getValue();
            accidental = getAccidental (val);
            romNum5.setText (accidental + "V", juce::dontSendNotification);
            alterationArray[4] = val - 1;
            break;
        case 5:
            val = noteAltSlider6.getValue();
            accidental = getAccidental (val);
            romNum6.setText (accidental + "VI", juce::dontSendNotification);
            alterationArray[5] = val - 1;
            break;
        case 6:
            val = noteAltSlider7.getValue();
            accidental = getAccidental (val);
            romNum7.setText (accidental + "VII", juce::dontSendNotification);
            alterationArray[6] = val - 1;
            break;
        default:
            break;
    }
}
