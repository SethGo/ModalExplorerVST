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
    // TODO: most of these attributes can come from a custom LookAndFeel. Colors need to be vars.
    
    // Key knob
    addAndMakeVisible(keyKnob);
    keyKnob.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    keyKnob.setRange (0, 11, 1);
    keyKnob.setValue (0);
    keyKnob.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    keyKnob.setLookAndFeel (&knobLookAndFeel);
    keyKnob.addListener(this);
    addAndMakeVisible(keyKnobLabel);
    keyKnobLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    keyKnobLabel.setFont(25.0f);
    keyKnobLabel.setText("C", juce::NotificationType::dontSendNotification);
    keyKnobLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(keyRomanNumLabel);
    keyRomanNumLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    keyRomanNumLabel.setFont(25.0f);
    keyRomanNumLabel.setJustificationType(juce::Justification::centred);
    keyRomanNumLabel.setText("I", juce::NotificationType::dontSendNotification);
    
    // Note alteration sliders
    addAndMakeVisible(noteAltSlider2);
    noteAltSlider2.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider2.setRange (0, 2, 1);
    noteAltSlider2.setValue (1);
    noteAltSlider2.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider2.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider2.addListener(this);
    addAndMakeVisible(noteAltLabel2);
    noteAltLabel2.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    noteAltLabel2.setFont(25.0f);
    noteAltLabel2.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(noteAltSlider3);
    noteAltSlider3.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider3.setRange (0, 2, 1);
    noteAltSlider3.setValue (1);
    noteAltSlider3.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider3.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider3.addListener(this);
    addAndMakeVisible(noteAltLabel3);
    noteAltLabel3.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    noteAltLabel3.setFont(25.0f);
    noteAltLabel3.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(noteAltSlider4);
    noteAltSlider4.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider4.setRange (0, 2, 1);
    noteAltSlider4.setValue (1);
    noteAltSlider4.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider4.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider4.addListener(this);
    addAndMakeVisible(noteAltLabel4);
    noteAltLabel4.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    noteAltLabel4.setFont(25.0f);
    noteAltLabel4.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(noteAltSlider5);
    noteAltSlider5.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider5.setRange (0, 2, 1);
    noteAltSlider5.setValue (1);
    noteAltSlider5.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider5.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider5.addListener(this);
    addAndMakeVisible(noteAltLabel5);
    noteAltLabel5.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    noteAltLabel5.setFont(25.0f);
    noteAltLabel5.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(noteAltSlider6);
    noteAltSlider6.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider6.setRange (0, 2, 1);
    noteAltSlider6.setValue (1);
    noteAltSlider6.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider6.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider6.addListener(this);
    addAndMakeVisible(noteAltLabel6);
    noteAltLabel6.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    noteAltLabel6.setFont(25.0f);
    noteAltLabel6.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(noteAltSlider7);
    noteAltSlider7.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    noteAltSlider7.setRange (0, 2, 1);
    noteAltSlider7.setValue (1);
    noteAltSlider7.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    noteAltSlider7.setLookAndFeel (&customLookAndFeelCatSlider);
    noteAltSlider7.addListener(this);
    addAndMakeVisible(noteAltLabel7);
    noteAltLabel7.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    noteAltLabel7.setFont(25.0f);
    noteAltLabel7.setJustificationType(juce::Justification::centred);
    
    // Negative harmony button
    addAndMakeVisible(negHarmBtn);
    negHarmBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
    negHarmBtn.setColour(juce::TextButton::buttonColourId, juce::Colour(5, 41, 66));
    negHarmBtn.setColour(juce::TextButton::buttonOnColourId, juce::Colour(123, 234, 243));
    negHarmBtn.setColour(juce::ComboBox::outlineColourId, juce::Colour(224, 114, 82));
    negHarmBtn.onClick = [this]() { toggleNeg(); };
    
    // RB mode knob
    addAndMakeVisible(rbKnob);
    rbKnob.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    rbKnob.setRange (0, 18, 1);
    rbKnob.setValue (0);
    rbKnob.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    rbKnob.setLookAndFeel (&knobLookAndFeel);
    rbKnob.addListener(this);
    addAndMakeVisible(rbModeLabel);
    rbModeLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    rbModeLabel.setFont(25.0f);
    rbModeLabel.setJustificationType(juce::Justification::centred);
    rbModeLabel.setText("off", juce::NotificationType::dontSendNotification);
    
    // Glide slider
    addAndMakeVisible(glideSlider);
    glideSlider.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    glideSlider.setRange (0.0f, 1.0f, 0.01f);
    glideSlider.setValue (0.25);
    glideSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    glideSlider.setLookAndFeel (&customLookAndFeel);
    glideSlider.addListener(this);
    
    // Inversion knobs and labels
    addAndMakeVisible(invKnobS); //Soprano
    invKnobS.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    invKnobS.setRange (0, 7, 1);
    invKnobS.setValue (7);
    invKnobS.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobS.setLookAndFeel (&knobLookAndFeel);
    invKnobS.addListener(this);
    addAndMakeVisible(invKnobLabelS);
    invKnobLabelS.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    invKnobLabelS.setFont(25.0f);
    invKnobLabelS.setJustificationType(juce::Justification::centred);
    invKnobLabelS.attachToComponent(&invKnobS, false);
    
    addAndMakeVisible(invKnobA); //Alto
    invKnobA.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    invKnobA.setRange (0, 7, 1);
    invKnobA.setValue (5);
    invKnobA.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobA.setLookAndFeel (&knobLookAndFeel);
    invKnobA.addListener(this);
    addAndMakeVisible(invKnobLabelA);
    invKnobLabelA.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    invKnobLabelA.setFont(25.0f);
    invKnobLabelA.setJustificationType(juce::Justification::centred);
    invKnobLabelS.attachToComponent(&invKnobA, false);

    addAndMakeVisible(invKnobT); //Tenor
    invKnobT.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    invKnobT.setRange (0, 7, 1);
    invKnobT.setValue (3);
    invKnobT.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobT.setLookAndFeel (&knobLookAndFeel);
    invKnobT.addListener(this);
    addAndMakeVisible(invKnobLabelT);
    invKnobLabelT.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    invKnobLabelT.setFont(25.0f);
    invKnobLabelT.setJustificationType(juce::Justification::centred);
    invKnobLabelS.attachToComponent(&invKnobT, false);

    addAndMakeVisible(invKnobB); //Bass
    invKnobB.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    invKnobB.setRange (0, 7, 1);
    invKnobB.setValue (1);
    invKnobB.setTextBoxStyle (juce::Slider::NoTextBox, true, 0, 0);
    invKnobB.setLookAndFeel (&knobLookAndFeel);
    invKnobB.addListener(this);
    addAndMakeVisible(invKnobLabelB);
    invKnobLabelB.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    invKnobLabelB.setFont(25.0f);
    invKnobLabelB.setJustificationType(juce::Justification::centred);
    invKnobLabelS.attachToComponent(&invKnobB, false);
    
    // Oscillator selection combo boxes
    addAndMakeVisible(oscSelectComboS); // Soprano
    oscSelectComboS.addItem("saw", 1);
    oscSelectComboS.addItem("sqr", 2);
    oscSelectComboS.addItem("sin", 3);
    oscSelectComboS.setColour (juce::ComboBox::backgroundColourId, juce::Colour(5, 41, 66));
    oscSelectComboS.setColour (juce::ComboBox::arrowColourId, juce::Colour(224, 114, 82));
    oscSelectComboS.setColour (juce::ComboBox::outlineColourId, juce::Colour(123, 234, 243));
    oscSelectComboS.setColour (juce::ComboBox::textColourId, juce::Colour(123, 234, 243));
    oscSelectComboS.setSelectedId(1);
    oscSelectComboS.addListener(this);
    
    addAndMakeVisible(oscSelectComboA); // Alto
    oscSelectComboA.addItem("saw", 1);
    oscSelectComboA.addItem("sqr", 2);
    oscSelectComboA.addItem("sin", 3);
    oscSelectComboA.setColour (juce::ComboBox::backgroundColourId, juce::Colour(5, 41, 66));
    oscSelectComboA.setColour (juce::ComboBox::arrowColourId, juce::Colour(224, 114, 82));
    oscSelectComboA.setColour (juce::ComboBox::outlineColourId, juce::Colour(123, 234, 243));
    oscSelectComboA.setColour (juce::ComboBox::textColourId, juce::Colour(123, 234, 243));
    oscSelectComboA.setSelectedId(3);
    oscSelectComboA.addListener(this);
    
    addAndMakeVisible(oscSelectComboT); // Tenor
    oscSelectComboT.addItem("saw", 1);
    oscSelectComboT.addItem("sqr", 2);
    oscSelectComboT.addItem("sin", 3);
    oscSelectComboT.setColour (juce::ComboBox::backgroundColourId, juce::Colour(5, 41, 66));
    oscSelectComboT.setColour (juce::ComboBox::arrowColourId, juce::Colour(224, 114, 82));
    oscSelectComboT.setColour (juce::ComboBox::outlineColourId, juce::Colour(123, 234, 243));
    oscSelectComboT.setColour (juce::ComboBox::textColourId, juce::Colour(123, 234, 243));
    oscSelectComboT.setSelectedId(2);
    oscSelectComboT.addListener(this);
    
    addAndMakeVisible(oscSelectComboB); // Bass
    oscSelectComboB.addItem("saw", 1);
    oscSelectComboB.addItem("sqr", 2);
    oscSelectComboB.addItem("sin", 3);
    oscSelectComboB.setColour (juce::ComboBox::backgroundColourId, juce::Colour(5, 41, 66));
    oscSelectComboB.setColour (juce::ComboBox::arrowColourId, juce::Colour(224, 114, 82));
    oscSelectComboB.setColour (juce::ComboBox::outlineColourId, juce::Colour(123, 234, 243));
    oscSelectComboB.setColour (juce::ComboBox::textColourId, juce::Colour(123, 234, 243));
    oscSelectComboB.setSelectedId(1);
    oscSelectComboB.addListener(this);
    
    addAndMakeVisible(oscTypeLabel);
    oscTypeLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    oscTypeLabel.setFont(25.0f);
    oscTypeLabel.setJustificationType(juce::Justification::centredBottom);
    oscTypeLabel.setText("type", juce::NotificationType::dontSendNotification);
    
    
    // Oscillator mix bars
    addAndMakeVisible(oscMixBarS); // Soprano
    oscMixBarS.setSliderStyle (juce::Slider::SliderStyle::LinearBar);
    oscMixBarS.setRange (-100.0f, 10.0f, 0.01f);
    oscMixBarS.setValue (-10.0);
    oscMixBarS.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    oscMixBarS.setLookAndFeel (&customLookAndFeel);
    oscMixBarS.addListener(this);
    
    addAndMakeVisible(oscMixBarA); // Alto
    oscMixBarA.setSliderStyle (juce::Slider::SliderStyle::LinearBar);
    oscMixBarA.setRange (-100.0f, 10.0f, 0.01f);
    oscMixBarA.setValue (-10.0);
    oscMixBarA.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    oscMixBarA.setLookAndFeel (&customLookAndFeel);
    oscMixBarA.addListener(this);
    
    addAndMakeVisible(oscMixBarT); // Tenor
    oscMixBarT.setSliderStyle (juce::Slider::SliderStyle::LinearBar);
    oscMixBarT.setRange (-100.0f, 10.0f, 0.01f);
    oscMixBarT.setValue (-10.0);
    oscMixBarT.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    oscMixBarT.setLookAndFeel (&customLookAndFeel);
    oscMixBarT.addListener(this);
    
    addAndMakeVisible(oscMixBarB); // Bass
    oscMixBarB.setSliderStyle (juce::Slider::SliderStyle::LinearBar);
    oscMixBarB.setRange (-100.0f, 10.0f, 0.01f);
    oscMixBarB.setValue (-10.0);
    oscMixBarB.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    oscMixBarB.setLookAndFeel (&customLookAndFeel);
    oscMixBarB.addListener(this);
    
    addAndMakeVisible(oscMixLabel);
    oscMixLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    oscMixLabel.setFont(25.0f);
    oscMixLabel.setJustificationType(juce::Justification::centredBottom);
    oscMixLabel.setText("mix", juce::NotificationType::dontSendNotification);
    
    // Filter ADSR sliders
    addAndMakeVisible(filterSliderA); // Attack
    filterSliderA.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderA.setRange (0.0f, 1.0f, 0.01f);
    filterSliderA.setValue (0.08);
    filterSliderA.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderA.setLookAndFeel (&customLookAndFeel);
    filterSliderA.addListener(this);
    addAndMakeVisible(filterLabelA);
    filterLabelA.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    filterLabelA.setFont(25.0f);
    filterLabelA.setJustificationType(juce::Justification::centredBottom);
    filterLabelA.setText("A", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(filterSliderD); // Decay
    filterSliderD.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderD.setRange (0.0f, 1.0f, 0.01f);
    filterSliderD.setValue (0.63);
    filterSliderD.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderD.setLookAndFeel (&customLookAndFeel);
    filterSliderD.addListener(this);
    addAndMakeVisible(filterLabelD);
    filterLabelD.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    filterLabelD.setFont(25.0f);
    filterLabelD.setJustificationType(juce::Justification::centredBottom);
    filterLabelD.setText("D", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(filterSliderS); // Sustain
    filterSliderS.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderS.setRange (0.0f, 1.0f, 0.01f);
    filterSliderS.setValue (0.33);
    filterSliderS.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderS.setLookAndFeel (&customLookAndFeel);
    filterSliderS.addListener(this);
    addAndMakeVisible(filterLabelS);
    filterLabelS.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    filterLabelS.setFont(25.0f);
    filterLabelS.setJustificationType(juce::Justification::centredBottom);
    filterLabelS.setText("S", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(filterSliderR); // Release
    filterSliderR.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderR.setRange (0.0f, 1.0f, 0.01f);
    filterSliderR.setValue (0.3);
    filterSliderR.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderR.setLookAndFeel (&customLookAndFeel);
    filterSliderR.addListener(this);
    addAndMakeVisible(filterLabelR);
    filterLabelR.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    filterLabelR.setFont(25.0f);
    filterLabelR.setJustificationType(juce::Justification::centredBottom);
    filterLabelR.setText("R", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(filterTitleLabel);
    filterTitleLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    filterTitleLabel.setFont(25.0f);
    filterTitleLabel.setJustificationType(juce::Justification::centredBottom);
    filterTitleLabel.setText("filter", juce::NotificationType::dontSendNotification);
    
    // Amp ADSR sliders
    addAndMakeVisible(ampSliderA); // Attack
    ampSliderA.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderA.setRange (0.0f, 1.0f, 0.01f);
    ampSliderA.setValue (0.16f);
    ampSliderA.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderA.setLookAndFeel (&customLookAndFeel);
    ampSliderA.addListener(this);
    addAndMakeVisible(ampLabelA);
    ampLabelA.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    ampLabelA.setFont(25.0f);
    ampLabelA.setJustificationType(juce::Justification::centredBottom);
    ampLabelA.setText("A", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(ampSliderD); // Decay
    ampSliderD.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderD.setRange (0.0f, 1.0f, 0.01f);
    ampSliderD.setValue (0.0f);
    ampSliderD.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderD.setLookAndFeel (&customLookAndFeel);
    ampSliderD.addListener(this);
    addAndMakeVisible(ampLabelD);
    ampLabelD.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    ampLabelD.setFont(25.0f);
    ampLabelD.setJustificationType(juce::Justification::centredBottom);
    ampLabelD.setText("D", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(ampSliderS); // Sustain
    ampSliderS.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderS.setRange (0.0f, 1.0f, 0.01f);
    ampSliderS.setValue (1.0f);
    ampSliderS.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderS.setLookAndFeel (&customLookAndFeel);
    ampSliderS.addListener(this);
    addAndMakeVisible(ampLabelS);
    ampLabelS.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    ampLabelS.setFont(25.0f);
    ampLabelS.setJustificationType(juce::Justification::centredBottom);
    ampLabelS.setText("S", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(ampSliderR); // Release
    ampSliderR.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderR.setRange (0.0f, 1.0f, 0.01f);
    ampSliderR.setValue (0.49f);
    ampSliderR.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderR.setLookAndFeel (&customLookAndFeel);
    ampSliderR.addListener(this);
    addAndMakeVisible(ampLabelR);
    ampLabelR.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    ampLabelR.setFont(25.0f);
    ampLabelR.setJustificationType(juce::Justification::centredBottom);
    ampLabelR.setText("R", juce::NotificationType::dontSendNotification);
    
    addAndMakeVisible(ampTitleLabel);
    ampTitleLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    ampTitleLabel.setFont(25.0f);
    ampTitleLabel.setJustificationType(juce::Justification::centredBottom);
    ampTitleLabel.setText("amp", juce::NotificationType::dontSendNotification);
    
    // Filter controls
    addAndMakeVisible(resSlider); // Resonance
    resSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    resSlider.setRange (0.0f, 1.0f, 0.01f);
    resSlider.setValue (0.2f);
    resSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    resSlider.setLookAndFeel (&customLookAndFeel);
    resSlider.addListener(this);
    addAndMakeVisible(resLabel);
    resLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    resLabel.setFont(25.0f);
    resLabel.setJustificationType(juce::Justification::centred);
    resLabel.setText("res", juce::NotificationType::dontSendNotification);
    resLabel.attachToComponent(&resSlider, false);
    
    addAndMakeVisible(cutoffSlider); // Cutoff
    cutoffSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    cutoffSlider.setRange (2000.0f, 20000.0f, 1.0f);
    cutoffSlider.setValue (16000.0f);
    cutoffSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    cutoffSlider.setLookAndFeel (&customLookAndFeel);
    cutoffSlider.addListener(this);
    addAndMakeVisible(cuttoffLabel);
    cuttoffLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    cuttoffLabel.setFont(25.0f);
    cuttoffLabel.setJustificationType(juce::Justification::centred);
    cuttoffLabel.setText("cutoff", juce::NotificationType::dontSendNotification);
    cuttoffLabel.attachToComponent(&resSlider, false);
    
    //Output knob
    addAndMakeVisible(outputKnob); // Cutoff
    outputKnob.setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    outputKnob.setRange (0.0f, 1.0f, 0.01f);
    outputKnob.setValue (0.5);
    outputKnob.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    outputKnob.setLookAndFeel (&knobLookAndFeel);
    outputKnob.addListener(this);
    addAndMakeVisible(outputLabel);
    outputLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colour(224, 114, 82));
    outputLabel.setFont(25.0f);
    outputLabel.setJustificationType(juce::Justification::centred);
    outputLabel.setText("output", juce::NotificationType::dontSendNotification);
    outputLabel.attachToComponent(&resSlider, false);
    
    setSize (1035, 710);
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
        negHarmBtn.setColour(juce::TextButton::textColourOnId, juce::Colour(5, 41, 66));
        negHarmBtn.setButtonText("on");
        audioProcessor.negHarmMode = true;
    }
    else
    {
        negHarmBtn.setToggleState(false, juce::NotificationType::dontSendNotification);
        negHarmBtn.setColour(juce::TextButton::textColourOffId, juce::Colour(123, 234, 243));
        negHarmBtn.setButtonText("off");
        audioProcessor.negHarmMode = false;
    }
}

//==============================================================================
void ModalExplorerVSTAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(5, 41, 66));
    g.setColour (juce::Colour(123, 234, 243));
    g.setFont(20.0f);
    
    // Section box placement variables
    float corner = 8.5;
    int lineThickness = 7;
    int edgeMargin = 10;
    int scaleTitleXOffset = 50;
    int splitBetweenScaleAndVoicing = 190;
    int scaleSectionXOffset = 638;
    int negHarmXOffset = 109;
    int subtitleYOffset = 40;
    int inversionXOffest = 155;
    int chordXOffset = inversionXOffest;
    int oscXOffset = 288;
    int envelopeXOffset = 367;
    
    // Full outline box
    g.drawRoundedRectangle(edgeMargin, edgeMargin, getWidth() - edgeMargin*2, getHeight() - edgeMargin*2, corner, lineThickness);

    // Scale vertical title section
    g.drawRoundedRectangle(edgeMargin, edgeMargin, scaleTitleXOffset, splitBetweenScaleAndVoicing, corner, lineThickness);
    
    // Voicing vertical title section
    g.drawRoundedRectangle(edgeMargin, splitBetweenScaleAndVoicing + edgeMargin, scaleTitleXOffset, getHeight() - splitBetweenScaleAndVoicing - edgeMargin*2, corner, lineThickness);
    
    // Scale selection section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset, edgeMargin, scaleSectionXOffset, splitBetweenScaleAndVoicing, corner, lineThickness);
    
    // Neg-harm title section and text
    juce::Rectangle<float> negHarmTitleRect;
    negHarmTitleRect.setBounds(edgeMargin + scaleTitleXOffset + scaleSectionXOffset, edgeMargin, negHarmXOffset, subtitleYOffset);
    g.drawRoundedRectangle(negHarmTitleRect, corner, lineThickness);
    g.drawFittedText("NEG-HARM", negHarmTitleRect.toNearestInt(), juce::Justification::centred, 0);
    
    // Neg-Harm section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset + scaleSectionXOffset, edgeMargin + subtitleYOffset, negHarmXOffset, splitBetweenScaleAndVoicing - subtitleYOffset, corner, lineThickness);
    
    // RB mode title section and text
    juce::Rectangle<float> rbTitleRect;
    rbTitleRect.setBounds(edgeMargin + scaleTitleXOffset + scaleSectionXOffset + negHarmXOffset, edgeMargin, negHarmXOffset, subtitleYOffset);
    g.drawRoundedRectangle(rbTitleRect, corner, lineThickness);
    g.drawFittedText("RB MODE", rbTitleRect.toNearestInt(), juce::Justification::centred, 0);
    
    // RB mode section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset + scaleSectionXOffset + negHarmXOffset, edgeMargin + subtitleYOffset, negHarmXOffset, splitBetweenScaleAndVoicing - subtitleYOffset, corner, lineThickness);
    
    // Glide title section and text
    juce::Rectangle<float> glideTitleRect;
    glideTitleRect.setBounds(edgeMargin + scaleTitleXOffset + scaleSectionXOffset + negHarmXOffset*2, edgeMargin, negHarmXOffset, subtitleYOffset);
    g.drawRoundedRectangle(glideTitleRect, corner, lineThickness);

    g.drawFittedText("GLIDE", glideTitleRect.toNearestInt(), juce::Justification::centred, 0);

    // Glide section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset + scaleSectionXOffset + negHarmXOffset*2, edgeMargin + subtitleYOffset, negHarmXOffset, splitBetweenScaleAndVoicing - subtitleYOffset, corner, lineThickness);
    
    // Inversion title section and text
    juce::Rectangle<float> invTitleRect;
    invTitleRect.setBounds(edgeMargin + scaleTitleXOffset, splitBetweenScaleAndVoicing + edgeMargin, inversionXOffest, subtitleYOffset);
    g.drawRoundedRectangle(invTitleRect, corner, lineThickness);;
    g.drawFittedText("INVERSION", invTitleRect.toNearestInt(), juce::Justification::centred, 0);
    
    // Inversion section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset, splitBetweenScaleAndVoicing + edgeMargin + subtitleYOffset, inversionXOffest, getHeight() - splitBetweenScaleAndVoicing - edgeMargin*2 - subtitleYOffset, corner, lineThickness);
    
    // Chord title section and text
    juce::Rectangle<float> chordTitleRect;
    chordTitleRect.setBounds(edgeMargin + scaleTitleXOffset + inversionXOffest, splitBetweenScaleAndVoicing + edgeMargin, chordXOffset, subtitleYOffset);
    g.drawRoundedRectangle(chordTitleRect, corner, lineThickness);
    g.drawFittedText("CHORD", chordTitleRect.toNearestInt(), juce::Justification::centred, 0);
    
    // Chord section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset + inversionXOffest, splitBetweenScaleAndVoicing + edgeMargin + subtitleYOffset, chordXOffset, getHeight() - splitBetweenScaleAndVoicing - edgeMargin*2 - subtitleYOffset, corner, lineThickness);
    
    // Oscillators title section and text
    juce::Rectangle<float> oscTitleRect;
    oscTitleRect.setBounds(edgeMargin + scaleTitleXOffset + inversionXOffest + chordXOffset, splitBetweenScaleAndVoicing + edgeMargin, oscXOffset, subtitleYOffset);
    g.drawRoundedRectangle(oscTitleRect, corner, lineThickness);
    g.drawFittedText("OSCILLATORS", oscTitleRect.toNearestInt(), juce::Justification::centred, 0);
    
    // Oscillators section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset + inversionXOffest + chordXOffset, splitBetweenScaleAndVoicing + edgeMargin + subtitleYOffset, oscXOffset, getHeight() - splitBetweenScaleAndVoicing - edgeMargin*2 - subtitleYOffset, corner, lineThickness);
    
    // Envelopes title section and text
    juce::Rectangle<float> envTitleRect;
    envTitleRect.setBounds(edgeMargin + scaleTitleXOffset + inversionXOffest + chordXOffset + oscXOffset, splitBetweenScaleAndVoicing + edgeMargin, envelopeXOffset, subtitleYOffset);
    g.drawRoundedRectangle(envTitleRect, corner, lineThickness);
    g.drawFittedText("ENVELOPES", envTitleRect.toNearestInt(), juce::Justification::centred, 0);
    
    // Envelopes section
    g.drawRoundedRectangle(edgeMargin + scaleTitleXOffset + inversionXOffest + chordXOffset + oscXOffset, splitBetweenScaleAndVoicing + edgeMargin + subtitleYOffset, envelopeXOffset, getHeight() - splitBetweenScaleAndVoicing - edgeMargin*2 - subtitleYOffset, corner, lineThickness);

    // Vertical text for SCALE and VOICING titles
    juce::GlyphArrangement ga;
    ga.addLineOfText(juce::Font(25.0f), "SCALE", -136, 43);
    ga.addLineOfText(juce::Font(25.0f), "VOICING", -475, 43);
    juce::Path p;
    ga.createPath(p);
    p.applyTransform(juce::AffineTransform().rotated(juce::degreesToRadians(-90.0f), 0, 0));
    g.fillPath(p);
};

void ModalExplorerVSTAudioProcessorEditor::resized()
{
    // TODO: Get rid of all the numbers in the setBounds() calls...
    
    // Placement and sizing variables
    // Scale
    int keyKnobSize = 85;
    int keyKnobX = 80;
    int keyKnobY = 160;
    int keyKnobLabelX = 90;
    int keyKnobLabelY = 164;
    int keyRomanNumLabelX = 103;
    int keyRomanNumLabelY = 50;
    int noteAltsliderWidth = 40;
    int noteAltSliderHeight = 90;
    int noteAltSliderHorizSpacing = 85;
    int noteAltSliderX = 205; // TODO: Bring closer to keyKnob, de-couple neg-harm, rbKnob, and glideSlider.
    int noteAltSliderY = 72;
    
    // Extras (Neg-Harm, RB mode, Glide)
    int negHarmBtnSize = 50;
    int negHarmBtnX = 729;
    int negHarmBtnY = noteAltSliderY + 25;
    int rbKnobSize = keyKnobSize;
    int rbKnobX = 820;
    int rbKnobY = 75;
    int rbKnobLabelX = 841;
    int glideSliderX = 947;
    int glideSliderY = 63;
    
    // Inversion
    int invKnobX = keyKnobX - 18;
    int invKnobY = 240;
    int invKnobSize = 125;
    int invKnobVertSpacing = 110;
    
    // Oscillators
    int oscComboBoxWidth = 70;
    int oscComboX = 400;
    int oscComboY = invKnobY + invKnobSize/2 - 10;
    int oscMixBarX = 505;
    int oscMixBarY = oscComboY;
    int oscTypeLabelX = oscComboX + 2;
    int oscMixLabelX = oscMixBarX + 42;
    
    // Fliter and amp ADSR
    int filterADSRX = 677;
    int adsrY = oscMixBarY - 13;
    int adsrSpacing = 35;
    int ampADSRX = filterADSRX + adsrSpacing*5;
    int adsrWidth = 40;
    int adsrHeight = 130;
    int filterTitleX = filterADSRX + 44;
    int ampTitleX = ampADSRX + 44;
    int adsrTitleY = adsrY - 33;
    int adsrLettersY = adsrY + 130;
    
    // Cutoff, res, output
    int cutoffSize = 100;
    int cutoffX = filterADSRX + 22;
    int cutoffY = 592;
    int cutoffLabelX = cutoffX + 15;
    int cutoffLabelY = cutoffY - 20;
    int resSize = 65;
    int resX = 717;
    int resY = cutoffY - 100;
    int resLabelX = resX + 13;
    int resLabelY = resY - 20;
    int outputKnobSize = 155;
    int outputX = ampADSRX - 5;
    int outputY = 507;
    int outputLabelX = outputX + 40;
    int outputLabelY = outputY - 25;
    
    // Key knob
    
    keyKnob.setBounds(keyKnobX, keyKnobY - keyKnobSize, keyKnobSize, keyKnobSize);
    keyKnobLabel.setBounds(keyKnobLabelX, keyKnobLabelY, 65, 20);
    keyRomanNumLabel.setBounds(keyRomanNumLabelX, keyRomanNumLabelY, 40, 20);
    
    // Note alteration sliders
    noteAltSlider2.setBounds(noteAltSliderX, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider3.setBounds(noteAltSliderX + noteAltSliderHorizSpacing, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider4.setBounds(noteAltSliderX + noteAltSliderHorizSpacing*2, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider5.setBounds(noteAltSliderX + noteAltSliderHorizSpacing*3, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider6.setBounds(noteAltSliderX + noteAltSliderHorizSpacing*4, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    noteAltSlider7.setBounds(noteAltSliderX + noteAltSliderHorizSpacing*5, noteAltSliderY, noteAltsliderWidth, noteAltSliderHeight);
    
    // Negative harmony button
    negHarmBtn.setBounds(negHarmBtnX, negHarmBtnY, negHarmBtnSize, negHarmBtnSize);
    
    // RB mode knob
    rbKnob.setBounds(rbKnobX, rbKnobY, rbKnobSize, rbKnobSize);
    rbModeLabel.setBounds(rbKnobLabelX, keyKnobLabelY, 40, 20);
    
    // Glide slider
    glideSlider.setBounds(glideSliderX, glideSliderY, 40, 120);
    
    // Inversion knobs
    invKnobS.setBounds(invKnobX, invKnobY, invKnobSize, invKnobSize);
    invKnobA.setBounds(invKnobX, invKnobY + invKnobVertSpacing, invKnobSize, invKnobSize);
    invKnobT.setBounds(invKnobX, invKnobY + invKnobVertSpacing*2, invKnobSize, invKnobSize);
    invKnobB.setBounds(invKnobX, invKnobY + invKnobVertSpacing*3, invKnobSize, invKnobSize);
    
    // Oscillator selection combo boxes
    oscSelectComboS.setBounds(oscComboX, oscComboY, oscComboBoxWidth, 20);
    oscSelectComboA.setBounds(oscComboX, oscComboY + invKnobVertSpacing, oscComboBoxWidth, 20);
    oscSelectComboT.setBounds(oscComboX, oscComboY + invKnobVertSpacing*2, oscComboBoxWidth, 20);
    oscSelectComboB.setBounds(oscComboX, oscComboY + invKnobVertSpacing*3, oscComboBoxWidth, 20);
    oscTypeLabel.setBounds(oscTypeLabelX, adsrTitleY, 70, 30);
    
    // Oscillator mix slider bars
    oscMixBarS.setBounds(oscMixBarX, oscMixBarY, 130, 20);
    oscMixBarA.setBounds(oscMixBarX, oscMixBarY + invKnobVertSpacing, 130, 20);
    oscMixBarT.setBounds(oscMixBarX, oscMixBarY + invKnobVertSpacing*2, 130, 20);
    oscMixBarB.setBounds(oscMixBarX, oscMixBarY + invKnobVertSpacing*3, 130, 20);
    oscMixLabel.setBounds(oscMixLabelX, adsrTitleY, 50, 30);
    
    // Filter ADSR
    filterSliderA.setBounds(filterADSRX, adsrY, adsrWidth, adsrHeight);
    filterSliderD.setBounds(filterADSRX + adsrSpacing, adsrY, adsrWidth, adsrHeight);
    filterSliderS.setBounds(filterADSRX + adsrSpacing*2, adsrY, adsrWidth, adsrHeight);
    filterSliderR.setBounds(filterADSRX + adsrSpacing*3, adsrY, adsrWidth, adsrHeight);
    filterLabelA.setBounds(filterADSRX, adsrLettersY, 40, 25);
    filterLabelD.setBounds(filterADSRX + adsrSpacing, adsrLettersY, 40, 25);
    filterLabelS.setBounds(filterADSRX + adsrSpacing*2, adsrLettersY, 40, 25);
    filterLabelR.setBounds(filterADSRX + adsrSpacing*3, adsrLettersY, 40, 25);
    filterTitleLabel.setBounds(filterTitleX, adsrTitleY, 60, 30);
    
    // Amp ADSR
    ampSliderA.setBounds(ampADSRX, adsrY, adsrWidth, adsrHeight);
    ampSliderD.setBounds(ampADSRX + adsrSpacing, adsrY, adsrWidth, adsrHeight);
    ampSliderS.setBounds(ampADSRX + adsrSpacing*2, adsrY, adsrWidth, adsrHeight);
    ampSliderR.setBounds(ampADSRX + adsrSpacing*3, adsrY, adsrWidth, adsrHeight);
    ampLabelA.setBounds(ampADSRX, adsrLettersY, 40, 25);
    ampLabelD.setBounds(ampADSRX + adsrSpacing, adsrLettersY, 40, 25);
    ampLabelS.setBounds(ampADSRX + adsrSpacing*2, adsrLettersY, 40, 25);
    ampLabelR.setBounds(ampADSRX + adsrSpacing*3, adsrLettersY, 40, 25);
    ampTitleLabel.setBounds(ampTitleX, adsrTitleY, 60, 30);
    
    // Filter cutoff and resonance
    resSlider.setBounds(resX, resY, resSize, resSize);
    resLabel.setBounds(resLabelX, resLabelY, 40, 20);
    cutoffSlider.setBounds(cutoffX, cutoffY, cutoffSize, cutoffSize);
    cuttoffLabel.setBounds(cutoffLabelX, cutoffLabelY, 70, 20);
    
    // Output
    outputKnob.setBounds(outputX, outputY, outputKnobSize, outputKnobSize);
    outputLabel.setBounds(outputLabelX, outputLabelY, 75, 30);
};

std::string keyKnobValToKeyString(int keyKnobVal)
{
    std::string str;
    switch (keyKnobVal) {
        case 0:
            str = "C";
            break;
        case 1:
            str = "C#/Db";
            break;
        case 2:
            str = "D";
            break;
        case 3:
            str = "D#/Eb";
            break;
        case 4:
            str = "E";
            break;
        case 5:
            str = "F";
            break;
        case 6:
            str = "F#/Gb";
            break;
        case 7:
            str = "G";
            break;
        case 8:
            str = "G#/Ab";
            break;
        case 9:
            str = "A";
            break;
        case 10:
            str = "A#/Bb";
            break;
        case 11:
            str = "B";
            break;
        default:
            break;
    }
    return str;
};

std::string knobValToString(int invKnobVal)
{
    std::string str = invKnobVal == 0 ? "off" : std::to_string(invKnobVal);
    return str;
};

std::string noteAltValToString(int noteAltSliderVal, std::string sliderNum)
{
    std::string alt;
    switch (noteAltSliderVal) {
        case 0:
            alt = "b";
            break;
        case 1:
            alt = " ";
            break;
        case 2:
            alt = "#";
            break;
        default:
            break;
    }
    return alt + sliderNum;
};

std::string rbModeValToString(int rbKnobVal)
{
    return "nuh";
};

void ModalExplorerVSTAudioProcessorEditor::sliderValueChanged (juce::Slider *slider) //
{
    // TODO: Is there some way to do this with a switch instead of the endless else-if statements?

    // Spacing/sizing variables for updating labels
    int labelW = 50;
    int labelH = 20;
    int keyKnobLabelX = 85;
    int keyKnobLablY = 164;
    int noteAltLabelX = 200;
    int noteAltLabelY = 50;
    int noteAltLabelSpace = 85;
    int invKnobLabelX = 165;
    int invKnobLabelY = 280;
    int invKnobVertSpace = 110;
    int rbKnobLabelX = 836;
    
    // Key knob
    if (slider == &keyKnob)
    {
        int val = static_cast<int>(keyKnob.getValue());
        audioProcessor.keyVal = val;
        // Update label
        std::string str = keyKnobValToKeyString(val);
        keyKnobLabel.setText(str, juce::NotificationType::dontSendNotification);
        keyKnobLabel.setBounds(keyKnobLabelX, keyKnobLablY, labelW + 25, labelH);
    }
    
    // Note alteration sliders
    else if (slider == &noteAltSlider2)
    {
        int val = static_cast<int>(noteAltSlider2.getValue());
        audioProcessor.noteAltSliderVal2 = val;
        // Update label
        std::string str = noteAltValToString(val, "II");
        noteAltLabel2.setText(str, juce::NotificationType::dontSendNotification);
        noteAltLabel2.setBounds(noteAltLabelX, noteAltLabelY, labelW, labelH);
    }
    else if (slider == &noteAltSlider3)
    {
        int val = static_cast<int>(noteAltSlider3.getValue());
        audioProcessor.noteAltSliderVal3 = val;
        // Update label
        std::string str = noteAltValToString(val, "III");
        noteAltLabel3.setText(str, juce::NotificationType::dontSendNotification);
        noteAltLabel3.setBounds(noteAltLabelX + noteAltLabelSpace, noteAltLabelY, labelW, labelH);
    }
    else if (slider == &noteAltSlider4)
    {
        int val = static_cast<int>(noteAltSlider4.getValue());
        audioProcessor.noteAltSliderVal4 = val;
        // Update label
        std::string str = noteAltValToString(val, "IV");
        noteAltLabel4.setText(str, juce::NotificationType::dontSendNotification);
        noteAltLabel4.setBounds(noteAltLabelX + noteAltLabelSpace*2, noteAltLabelY, labelW, labelH);
    }
    else if (slider == &noteAltSlider5)
    {
        int val = static_cast<int>(noteAltSlider5.getValue());
        audioProcessor.noteAltSliderVal5 = val;
        // Update label
        std::string str = noteAltValToString(val, "V");
        noteAltLabel5.setText(str, juce::NotificationType::dontSendNotification);
        noteAltLabel5.setBounds(noteAltLabelX + noteAltLabelSpace*3, noteAltLabelY, labelW, labelH);
    }
    else if (slider == &noteAltSlider6)
    {
        int val = static_cast<int>(noteAltSlider6.getValue());
        audioProcessor.noteAltSliderVal6 = val;
        // Update label
        std::string str = noteAltValToString(val, "VI");
        noteAltLabel6.setText(str, juce::NotificationType::dontSendNotification);
        noteAltLabel6.setBounds(noteAltLabelX + noteAltLabelSpace*4, noteAltLabelY, labelW, labelH);
    }
    else if (slider == &noteAltSlider7)
    {
        int val = static_cast<int>(noteAltSlider7.getValue());
        audioProcessor.noteAltSliderVal7 = val;
        // Update label
        std::string str = noteAltValToString(val, "VII");
        noteAltLabel7.setText(str, juce::NotificationType::dontSendNotification);
        noteAltLabel7.setBounds(noteAltLabelX + noteAltLabelSpace*5, noteAltLabelY, labelW, labelH);
    }
    
    // RB knob
    else if (slider == &rbKnob)
    {
        int val = static_cast<int>(rbKnob.getValue());
        audioProcessor.rbModeVal = val;
        // Update label
        std::string str = knobValToString(val);
        rbModeLabel.setText(str, juce::NotificationType::dontSendNotification);
        rbModeLabel.setBounds(rbKnobLabelX, keyKnobLablY, labelW, labelH);
    }
    
    // Glide slider
    else if (slider == &glideSlider)
    {
        audioProcessor.glideSliderVal = glideSlider.getValue();
    }
    
    // Inversion knobs
    else if (slider == &invKnobS)
    {
        int val = static_cast<int>(invKnobS.getValue());
        audioProcessor.invKnobValS = val;
        // Update label
        std::string str = knobValToString(val);
        invKnobLabelS.setText(str, juce::NotificationType::dontSendNotification);
        invKnobLabelS.setBounds(invKnobLabelX, invKnobLabelY, labelW, labelH);
    }
    else if (slider == &invKnobA)
    {
        int val = static_cast<int>(invKnobA.getValue());
        audioProcessor.invKnobValA = val;
        // Update label
        std::string str = knobValToString(val);
        invKnobLabelA.setText(str, juce::NotificationType::dontSendNotification);
        invKnobLabelA.setBounds(invKnobLabelX, invKnobLabelY + invKnobVertSpace, labelW, labelH);
    }
    else if (slider == &invKnobT)
    {
        int val = static_cast<int>(invKnobT.getValue());
        audioProcessor.invKnobValT = val;
        // Update label
        std::string str = knobValToString(val);
        invKnobLabelT.setText(str, juce::NotificationType::dontSendNotification);
        invKnobLabelT.setBounds(invKnobLabelX, invKnobLabelY + invKnobVertSpace*2, labelW, labelH);
    }
    else if (slider == &invKnobB)
    {
        int val = static_cast<int>(invKnobB.getValue());
        audioProcessor.invKnobValB = val;
        // Update label
        std::string str = knobValToString(val);
        invKnobLabelB.setText(str, juce::NotificationType::dontSendNotification);
        invKnobLabelB.setBounds(invKnobLabelX, invKnobLabelY + invKnobVertSpace*3, labelW, labelH);
    }
    
    // Oscillator mix slider bars
    else if (slider == &oscMixBarS)
    {
        audioProcessor.oscMixValS = oscMixBarS.getValue();
    }
    else if (slider == &oscMixBarA)
    {
        audioProcessor.oscMixValA = oscMixBarA.getValue();
    }
    else if (slider == &oscMixBarT)
    {
        audioProcessor.oscMixValT = oscMixBarT.getValue();
    }
    else if (slider == &oscMixBarB)
    {
        audioProcessor.oscMixValB = oscMixBarB.getValue();
    }
    
    // Filter ADSR
    else if (slider == &filterSliderA)
    {
        audioProcessor.filterAVal = filterSliderA.getValue();
    }
    else if (slider == &filterSliderD)
    {
        audioProcessor.filterDVal = filterSliderD.getValue();
    }
    else if (slider == &filterSliderS)
    {
        audioProcessor.filterSVal = filterSliderS.getValue();
    }
    else if (slider == &filterSliderR)
    {
        audioProcessor.filterRVal = filterSliderR.getValue();
    }
    
    // Amp ADSR
    else if (slider == &ampSliderA)
    {
        audioProcessor.ampAVal = ampSliderA.getValue();
    }
    else if (slider == &ampSliderD)
    {
        audioProcessor.ampDVal = ampSliderD.getValue();
    }
    else if (slider == &ampSliderS)
    {
        audioProcessor.ampSVal = ampSliderS.getValue();
    }
    else if (slider == &ampSliderR)
    {
        audioProcessor.ampRVal = ampSliderR.getValue();
    }
    
    // Cutoff and res
    else if (slider == &cutoffSlider)
    {
        audioProcessor.cutoffVal = cutoffSlider.getValue();
    }
    else if (slider == &resSlider)
    {
        audioProcessor.resVal = resSlider.getValue();
    }
    
    // Output knob
    else if (slider == &outputKnob)
    {
        audioProcessor.outputVal = outputKnob.getValue();
    }
}

// Function to handle combo box oscillator-type selection
void ModalExplorerVSTAudioProcessorEditor::comboBoxChanged (juce::ComboBox *comboBox)
{
    // TODO: Should be able to do with a switch
    
    if (comboBox == &oscSelectComboS)
    {
        audioProcessor.oscSelectValS = oscSelectComboS.getSelectedId();
    }
    else if (comboBox == &oscSelectComboA)
    {
        audioProcessor.oscSelectValA = oscSelectComboA.getSelectedId();
    }
    else if (comboBox == &oscSelectComboT)
    {
        audioProcessor.oscSelectValT = oscSelectComboT.getSelectedId();
    }
    else if (comboBox == &oscSelectComboB)
    {
        audioProcessor.oscSelectValB = oscSelectComboB.getSelectedId();
    }
}

