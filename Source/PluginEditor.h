/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
// Custom LookAndFeels
class CustomLookAndFeel : public juce::LookAndFeel_V4
{
    public:
    CustomLookAndFeel()
    {
        auto orangePastel = juce::Colour(224, 114, 82);
        auto darkBlue = juce::Colour(5, 41, 66);
        auto brightBlue = juce::Colour(123, 234, 243);
        
        // Knob settings
        setColour (juce::Slider::thumbColourId, orangePastel);
        setColour (juce::Slider::rotarySliderOutlineColourId, brightBlue);
        setColour (juce::Slider::rotarySliderFillColourId, orangePastel);
        
        // Slider settings
        setColour (juce::Slider::backgroundColourId, brightBlue);
        setColour (juce::Slider::trackColourId, orangePastel);
        
        // ComboBox settings
        setColour (juce::ComboBox::backgroundColourId, darkBlue);
        setColour (juce::ComboBox::arrowColourId, orangePastel);
        setColour (juce::ComboBox::outlineColourId, brightBlue);
        setColour (juce::ComboBox::textColourId, brightBlue);
        
        // TextButton settings
        setColour (juce::TextButton::textColourOffId, brightBlue);
        setColour (juce::TextButton::buttonColourId, darkBlue);
        setColour (juce::TextButton::buttonOnColourId, brightBlue);
        
        // Label settings
        setColour (juce::Label::ColourIds::textColourId, orangePastel);
    }
};

class KnobLookAndFeel : public CustomLookAndFeel
{
    public:
    void drawRotarySlider (juce::Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider &slider) override
        {
            float outlineThickness = 2.5f;
            float diameter = width - (outlineThickness + 30);
            
            float radius = diameter/2;
            float centerX = x + width/2;
            float centerY = y + height /2;
            float rx = centerX - radius;
            float ry = centerY - radius;
            float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
            
            // Circular knob overlay
            juce::Rectangle<float> knobArea (rx, ry, diameter, diameter);
            g.setColour (juce::Colour(123, 234, 243));
            g.fillEllipse (knobArea);
            
            // Knob tick line
            g.setColour (juce::Colours::black );
            juce::Path knobLine;
            knobLine.addRectangle (0, -radius, 4.0f, radius/2);
            g.fillPath (knobLine, juce::AffineTransform::rotation(angle).translated(centerX, centerY));
            g.setColour (juce::Colour(224, 114, 82));
            g.drawEllipse (rx, ry, diameter, diameter, outlineThickness);
        }
};

// For sliders that control categorical parameters
class CustomLookAndFeelCatSlider : public CustomLookAndFeel
{
    public:
    CustomLookAndFeelCatSlider()
    {
        setColour (juce::Slider::rotarySliderFillColourId, juce::Colour(123, 234, 243));
        setColour (juce::Slider::trackColourId, juce::Colour(123, 234, 243));
    }
};

class ModalExplorerVSTAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                              public juce::Slider::Listener,
                                              public juce::ComboBox::Listener
{
public:
    ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor&);
    ~ModalExplorerVSTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override;
    void toggleNeg();
    void comboBoxChanged (juce::ComboBox* comboBox) override;

private:
    // Key knob
    juce::Slider keyKnob;
    juce::Label keyKnobLabel;
    juce::Label keyRomanNumLabel;
    
    // Note alteration sliders
    juce::Slider noteAltSlider2, noteAltSlider3, noteAltSlider4, noteAltSlider5, noteAltSlider6, noteAltSlider7;
    juce::Label noteAltLabel2, noteAltLabel3, noteAltLabel4, noteAltLabel5, noteAltLabel6, noteAltLabel7;
    
    // Negative harmony button
    juce::TextButton negHarmBtn { "off" };
    
    // RB mode knob
    juce::Slider rbKnob;
    juce::Label rbModeLabel;
    
    // Glide
    juce::Slider glideSlider;
    
    // Inversion knobs  (given as SATB)
    juce::Slider invKnobS, invKnobA, invKnobT, invKnobB;
    juce::Label invKnobLabelS, invKnobLabelA, invKnobLabelT, invKnobLabelB;
    
    // Oscillator waveform selection combo boxes (given as SATB)
    juce::ComboBox oscSelectComboS, oscSelectComboA, oscSelectComboT, oscSelectComboB;
    juce::Label oscTypeLabel;
    
    // Oscillator mix horizontal slider bars
    juce::Slider oscMixBarS, oscMixBarA, oscMixBarT, oscMixBarB;
    juce::Label oscMixLabel;
    
    // Filter ADSR sliders
    juce::Slider filterSliderA, filterSliderD, filterSliderS, filterSliderR;
    juce::Label filterLabelA, filterLabelD, filterLabelS, filterLabelR;
    juce::Label filterTitleLabel;
    
    // Amp ADSR sliders
    juce::Slider ampSliderA, ampSliderD, ampSliderS, ampSliderR;
    juce::Label ampLabelA, ampLabelD, ampLabelS, ampLabelR;
    juce::Label ampTitleLabel;
    
    // Cutoff and resonance rotary sliders
    juce::Slider cutoffSlider, resSlider;
    juce::Label cuttoffLabel, resLabel;
    
    // Output knob
    juce::Slider outputKnob;
    juce::Label outputLabel;
    
    // Section heading titles
    juce::Label scaleHeading;
    juce::Label voicingHeading;
    juce::Label glideHeading;
    juce::Label invHeading;
    juce::Label chordHeading;
    juce::Label oscHeading;
    juce::Label envHeading;
    
    // Colours
    juce::Colour orangePastel = juce::Colour(224, 114, 82);
    juce::Colour darkBlue = juce::Colour(5, 41, 66);
    juce::Colour brightBlue = juce::Colour(123, 234, 243);
    
    // Custom LookAndFeel's
    KnobLookAndFeel knobLookAndFeel;
    CustomLookAndFeel customLookAndFeel;
    CustomLookAndFeelCatSlider customLookAndFeelCatSlider;
    
    
    ModalExplorerVSTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessorEditor)
};
