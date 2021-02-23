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
ScaleSelectionComponent::ScaleSelectionComponent(ModalExplorerVSTAudioProcessor& p)
: audioProcessor (p)
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
    
    keyKnobAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "KEY", keyKnob);
    
    // Note alteration sliders
    addAndMakeVisible (noteAltSlider2);
    noteAltSlider2.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider2.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider2.setRange (0, 2, 1);
    noteAltSlider2.setValue (1);
    noteAltSlider2.onValueChange = [this] { changeNote(1); }; // scale degree 2 is '1' in the array
    
    noteAltSlider2Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT2", noteAltSlider2);
    
    addAndMakeVisible (noteAltSlider3);
    noteAltSlider3.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider3.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider3.setRange (0, 2, 1);
    noteAltSlider3.setValue (1);
    noteAltSlider3.onValueChange = [this] { changeNote(2); };
    
    noteAltSlider3Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT3", noteAltSlider3);
    
    addAndMakeVisible (noteAltSlider4);
    noteAltSlider4.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider4.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider4.setRange (0, 2, 1);
    noteAltSlider4.setValue (1);
    noteAltSlider4.onValueChange = [this] { changeNote(3); };
    
    noteAltSlider4Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT4", noteAltSlider4);
    
    addAndMakeVisible (noteAltSlider5);
    noteAltSlider5.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider5.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider5.setRange (0, 2, 1);
    noteAltSlider5.setValue (1);
    noteAltSlider5.onValueChange = [this] { changeNote(4); };
    
    noteAltSlider5Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT5", noteAltSlider5);
    
    addAndMakeVisible (noteAltSlider6);
    noteAltSlider6.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider6.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider6.setRange (0, 2, 1);
    noteAltSlider6.setValue (1);
    noteAltSlider6.onValueChange = [this] { changeNote(5); };
    
    noteAltSlider6Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT6", noteAltSlider6);
    
    addAndMakeVisible (noteAltSlider7);
    noteAltSlider7.setSliderStyle (juce::Slider::LinearVertical);
    noteAltSlider7.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider7.setRange (0, 2, 1);
    noteAltSlider7.setValue (1);
    noteAltSlider7.onValueChange = [this] { changeNote(6); };
    
    noteAltSlider7Attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "ALT7", noteAltSlider7);
    
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

ScaleSelectionComponent::~ScaleSelectionComponent()
{
}

void ScaleSelectionComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
}

void ScaleSelectionComponent::resized()
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

void ScaleSelectionComponent::updateScale()
{

    // int base[7] = BASE_SCALE;
    // if NegHarmOn ... change base scale to negative base scale
    
    // int tempAltArr[7] = alterationArray;
    // if rb mode then ... turn off note alt functionality, change tempAltArr to rbAltArr, move noteAltSliders

    // ELSE, this normal way of assigning scale...
    
    for (int i = 0; i < 7; i++)
    {
        scale[i] = (BASE_SCALE[i] + (int)keyKnob.getValue() + alterationArray[i]) % 12;
//        scale[i] = (base[i] + (int)keyKnob.getValue() + tempAltArr[i]) % 12;
    }
    
    note2.setText (noteNames[scale[1]], juce::NotificationType::dontSendNotification);
    note3.setText (noteNames[scale[2]], juce::NotificationType::dontSendNotification);
    note4.setText (noteNames[scale[3]], juce::NotificationType::dontSendNotification);
    note5.setText (noteNames[scale[4]], juce::NotificationType::dontSendNotification);
    note6.setText (noteNames[scale[5]], juce::NotificationType::dontSendNotification);
    note7.setText (noteNames[scale[6]], juce::NotificationType::dontSendNotification);
}

void ScaleSelectionComponent::changeKey()
{
    std::string keyString = noteNames [(int)keyKnob.getValue()];
    note1.setText (keyString, juce::dontSendNotification);
    updateScale();
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

int ScaleSelectionComponent::getAlterationValue (std::string accidental)
{
    // Get chromatic alteration from accidental
    int alterationValue;
    if (accidental == "b")
    {
        alterationValue = -1;
    }
    else if (accidental == " ")
    {
        alterationValue = 0;
    }
    else
    {
        alterationValue = 1;
    }
    return alterationValue;
}

void ScaleSelectionComponent::changeNote (int scaleDegree)
{
    std::string accidental;
    switch (scaleDegree) {
        case 1:
            accidental = getAccidental (noteAltSlider2.getValue());
            romNum2.setText (accidental + "II", juce::dontSendNotification);
            alterationArray[1] = getAlterationValue (accidental);
            break;
        case 2:
            accidental = getAccidental (noteAltSlider3.getValue());
            romNum3.setText (accidental + "III", juce::dontSendNotification);
            alterationArray[2] = getAlterationValue (accidental);
            break;
        case 3:
            accidental = getAccidental (noteAltSlider4.getValue());
            romNum4.setText (accidental + "IV", juce::dontSendNotification);
            alterationArray[3] = getAlterationValue (accidental);
            break;
        case 4:
            accidental = getAccidental (noteAltSlider5.getValue());
            romNum5.setText (accidental + "V", juce::dontSendNotification);
            alterationArray[4] = getAlterationValue (accidental);
            break;
        case 5:
            accidental = getAccidental (noteAltSlider6.getValue());
            romNum6.setText (accidental + "VI", juce::dontSendNotification);
            alterationArray[5] = getAlterationValue (accidental);
            break;
        case 6:
            accidental = getAccidental (noteAltSlider7.getValue());
            romNum7.setText (accidental + "VII", juce::dontSendNotification);
            alterationArray[6] = getAlterationValue (accidental);
            break;
        default:
            break;
    }
    updateScale();
}
