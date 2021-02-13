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
    
    // Eventually most of this needs to go into a custom LookAndFeel...
    
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
    glideSlider.setValue (0.25);
    glideSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
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
    invKnobB.addListener(this);
    
    // Oscillator selection combo boxes
    addAndMakeVisible(oscSelectComboS); // Soprano
    oscSelectComboS.addItem("saw", 1);
    oscSelectComboS.addItem("sqr", 2);
    oscSelectComboS.addItem("sin", 3);
    oscSelectComboS.setSelectedId(1);
    oscSelectComboS.addListener(this);
    
    addAndMakeVisible(oscSelectComboA); // Alto
    oscSelectComboA.addItem("saw", 1);
    oscSelectComboA.addItem("sqr", 2);
    oscSelectComboA.addItem("sin", 3);
    oscSelectComboA.setSelectedId(3);
    oscSelectComboA.addListener(this);
    
    addAndMakeVisible(oscSelectComboT); // Tenor
    oscSelectComboT.addItem("saw", 1);
    oscSelectComboT.addItem("sqr", 2);
    oscSelectComboT.addItem("sin", 3);
    oscSelectComboT.setSelectedId(2);
    oscSelectComboT.addListener(this);
    
    addAndMakeVisible(oscSelectComboB); // Bass
    oscSelectComboB.addItem("saw", 1);
    oscSelectComboB.addItem("sqr", 2);
    oscSelectComboB.addItem("sin", 3);
    oscSelectComboB.setSelectedId(1);
    oscSelectComboB.addListener(this);
    
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
    
    // Filter ADSR sliders
    addAndMakeVisible(filterSliderA); // Attack
    filterSliderA.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderA.setRange (0.0f, 1.0f, 0.01f);
    filterSliderA.setValue (0.08);
    filterSliderA.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderA.setLookAndFeel (&customLookAndFeel);
    filterSliderA.addListener(this);
    
    addAndMakeVisible(filterSliderD); // Decay
    filterSliderD.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderD.setRange (0.0f, 1.0f, 0.01f);
    filterSliderD.setValue (0.63);
    filterSliderD.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderD.setLookAndFeel (&customLookAndFeel);
    filterSliderD.addListener(this);
    
    addAndMakeVisible(filterSliderS); // Sustain
    filterSliderS.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderS.setRange (0.0f, 1.0f, 0.01f);
    filterSliderS.setValue (0.33);
    filterSliderS.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderS.setLookAndFeel (&customLookAndFeel);
    filterSliderS.addListener(this);
    
    addAndMakeVisible(filterSliderR); // Release
    filterSliderR.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    filterSliderR.setRange (0.0f, 1.0f, 0.01f);
    filterSliderR.setValue (0.3);
    filterSliderR.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    filterSliderR.setLookAndFeel (&customLookAndFeel);
    filterSliderR.addListener(this);
    
    // Amp ADSR sliders
    addAndMakeVisible(ampSliderA); // Attack
    ampSliderA.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderA.setRange (0.0f, 1.0f, 0.01f);
    ampSliderA.setValue (0.16f);
    ampSliderA.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderA.setLookAndFeel (&customLookAndFeel);
    ampSliderA.addListener(this);
    
    addAndMakeVisible(ampSliderD); // Decay
    ampSliderD.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderD.setRange (0.0f, 1.0f, 0.01f);
    ampSliderD.setValue (0.0f);
    ampSliderD.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderD.setLookAndFeel (&customLookAndFeel);
    ampSliderD.addListener(this);
    
    addAndMakeVisible(ampSliderS); // Sustain
    ampSliderS.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderS.setRange (0.0f, 1.0f, 0.01f);
    ampSliderS.setValue (1.0f);
    ampSliderS.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderS.setLookAndFeel (&customLookAndFeel);
    ampSliderS.addListener(this);
    
    addAndMakeVisible(ampSliderR); // Release
    ampSliderR.setSliderStyle (juce::Slider::SliderStyle::LinearVertical);
    ampSliderR.setRange (0.0f, 1.0f, 0.01f);
    ampSliderR.setValue (0.49f);
    ampSliderR.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    ampSliderR.setLookAndFeel (&customLookAndFeel);
    ampSliderR.addListener(this);
    
    // Filter controls
    addAndMakeVisible(resSlider); // Resonance
    resSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    resSlider.setRange (0.0f, 1.0f, 0.01f);
    resSlider.setValue (0.2f);
    resSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    resSlider.setLookAndFeel (&customLookAndFeel);
    cutoffSlider.addListener(this);
    
    addAndMakeVisible(cutoffSlider); // Cutoff
    cutoffSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    cutoffSlider.setRange (2000.0f, 20000.0f, 1.0f);
    cutoffSlider.setValue (16000.0f);
    cutoffSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    cutoffSlider.setLookAndFeel (&customLookAndFeel);
    cutoffSlider.addListener(this);
    
    //Output knob
    addAndMakeVisible(outputKnob); // Cutoff
    outputKnob.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    outputKnob.setRange (0.0f, 1.0f, 0.01f);
    outputKnob.setValue (0.5);
    outputKnob.setTextBoxStyle (juce::Slider::NoTextBox, false, 0, 0);
    outputKnob.setLookAndFeel (&knobLookAndFeel);
    outputKnob.addListener(this);
    
    
    
    
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
    // Scale
    int keyKnobSize = 85;
    int keyKnobX = 80;
    int keyKnobY = 160;
    int noteAltsliderWidth = 40;
    int noteAltSliderHeight = 90;
    int noteAltSliderHorizSpacing = 90;
    int noteAltSliderX = keyKnobX + noteAltSliderHorizSpacing + noteAltsliderWidth;
    int noteAltSliderY = keyKnobY - keyKnobSize - 3;
    
    // Extras (Neg-Harm, RB mode, Glide)
    int negHarmBtnSize = 50;
    int negHarmBtnX = noteAltSliderX + noteAltSliderHorizSpacing*6 + 10;
    int negHarmBtnY = noteAltSliderY + 25;
    int rbKnobSize = keyKnobSize;
    int rbKnobX = negHarmBtnX + noteAltSliderHorizSpacing;
    int rbKnobY = keyKnobY - 35;
    int glideSliderX = rbKnobX + noteAltSliderHorizSpacing + 17;
    
    // Inversion
    int invKnobX = keyKnobX - 5;
    int invKnobY = keyKnobY * 1.5;
    int invKnobSize = 125;
    int invKnobVertSpacing = 100;
    
    // Oscillators
    int oscComboBoxWidth = 70;
    int oscComboX = keyKnobX + noteAltSliderHorizSpacing * 3.5;
    int oscComboY = invKnobY + invKnobSize/2 - 10;
    int oscMixBarX = oscComboX + noteAltSliderHorizSpacing + 20;
    int oscMixBarY = oscComboY;
    
    // Fliter and amp ADSR
    int filterADSRX = oscMixBarX + 172;
    int adsrY = oscMixBarY - 5;
    int adsrSpacing = 35;
    int ampADSRX = filterADSRX + adsrSpacing*5;
    int adsrWidth = 40;
    int adsrHeight = 130;
    
    // Cutoff, res, output
    int cutoffSize = 100;
    int cutoffX = filterADSRX + 25;
    int cutoffY = oscMixBarY + invKnobVertSpacing*2.5;
    int resSize = 65;
    int resX = cutoffX + 18;
    int resY = cutoffY - invKnobVertSpacing;
    int outputKnobSize = 155;
    int outputX = ampADSRX - 5;
    int outputY = cutoffY - 55;
    
    
    // 3 Draw the object with .setBounds()
    // Key knob
    keyKnob.setBounds(keyKnobX, keyKnobY - keyKnobSize, keyKnobSize, keyKnobSize);
    
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
    rbKnob.setBounds(rbKnobX, rbKnobY-40, rbKnobSize, rbKnobSize);
    
    // Glide slider
    glideSlider.setBounds(glideSliderX, noteAltSliderY, 40, 120);
    
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
    
    // Oscillator mix slider bars
    oscMixBarS.setBounds(oscMixBarX, oscMixBarY, 130, 20);
    oscMixBarA.setBounds(oscMixBarX, oscMixBarY + invKnobVertSpacing, 130, 20);
    oscMixBarT.setBounds(oscMixBarX, oscMixBarY + invKnobVertSpacing*2, 130, 20);
    oscMixBarB.setBounds(oscMixBarX, oscMixBarY + invKnobVertSpacing*3, 130, 20);
    
    // Filter ADSR
    filterSliderA.setBounds(filterADSRX, adsrY, adsrWidth, adsrHeight);
    filterSliderD.setBounds(filterADSRX + adsrSpacing, adsrY, adsrWidth, adsrHeight);
    filterSliderS.setBounds(filterADSRX + adsrSpacing*2, adsrY, adsrWidth, adsrHeight);
    filterSliderR.setBounds(filterADSRX + adsrSpacing*3, adsrY, adsrWidth, adsrHeight);
    
    // Amp ADSR
    ampSliderA.setBounds(ampADSRX, adsrY, adsrWidth, adsrHeight);
    ampSliderD.setBounds(ampADSRX + adsrSpacing, adsrY, adsrWidth, adsrHeight);
    ampSliderS.setBounds(ampADSRX + adsrSpacing*2, adsrY, adsrWidth, adsrHeight);
    ampSliderR.setBounds(ampADSRX + adsrSpacing*3, adsrY, adsrWidth, adsrHeight);
    
    // Filter cutoff and resonance
    cutoffSlider.setBounds(cutoffX, cutoffY, cutoffSize, cutoffSize);
    resSlider.setBounds(resX, resY, resSize, resSize);
    
    // Output
    outputKnob.setBounds(outputX, outputY, outputKnobSize, outputKnobSize);
    
    
    
}

// 9 Implement gui object listener
void ModalExplorerVSTAudioProcessorEditor::sliderValueChanged (juce::Slider *slider) //
{
    //10 Connect value of gui object to control variable such as...
    // "If the slider whose value was heard to have been changed by the listener is THIS particular slider, then do something with this control variable coming from the audio processor."
    
    // This should all be one big switch
    
    // Key knob
    if (slider == &keyKnob)
    {
        audioProcessor.keyVal = static_cast<int>(keyKnob.getValue());
    }
    
    // Note alteration sliders
    else if (slider == &noteAltSlider2)
    {
        audioProcessor.noteAltSliderVal2 = static_cast<int>(noteAltSlider2.getValue());
    }
    else if (slider == &noteAltSlider3)
    {
        audioProcessor.noteAltSliderVal3 = static_cast<int>(noteAltSlider3.getValue());
    }
    else if (slider == &noteAltSlider4)
    {
        audioProcessor.noteAltSliderVal4 = static_cast<int>(noteAltSlider4.getValue());
    }
    else if (slider == &noteAltSlider5)
    {
        audioProcessor.noteAltSliderVal5 = static_cast<int>(noteAltSlider5.getValue());
    }
    else if (slider == &noteAltSlider6)
    {
        audioProcessor.noteAltSliderVal6 = static_cast<int>(noteAltSlider6.getValue());
    }
    else if (slider == &noteAltSlider7)
    {
        audioProcessor.noteAltSliderVal7 = static_cast<int>(noteAltSlider7.getValue());
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
        audioProcessor.invKnobValS = static_cast<int>(invKnobS.getValue());
    }
    else if (slider == &invKnobA)
    {
        audioProcessor.invKnobValA = static_cast<int>(invKnobA.getValue());
    }
    else if (slider == &invKnobT)
    {
        audioProcessor.invKnobValT = static_cast<int>(invKnobT.getValue());
    }
    else if (slider == &invKnobB)
    {
        audioProcessor.invKnobValB = static_cast<int>(invKnobB.getValue());
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

