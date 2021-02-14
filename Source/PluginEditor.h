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
class KnobLookAndFeel : public juce::LookAndFeel_V4
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
            g.setColour(juce::Colour(123, 234, 243));
            g.fillEllipse(knobArea);
            
            // Knob tick line
            g.setColour(juce::Colours::black );
            juce::Path knobLine;
            knobLine.addRectangle(0, -radius, 4.0f, radius/2);
            g.fillPath(knobLine, juce::AffineTransform::rotation(angle).translated(centerX, centerY));
            g.setColour(juce::Colour(224, 114, 82));
            g.drawEllipse(rx, ry, diameter, diameter, outlineThickness);
        }
};

class CustomLookAndFeel : public juce::LookAndFeel_V4
{
    public:
    CustomLookAndFeel()
    {
        setColour(juce::Slider::thumbColourId, juce::Colour(224, 114, 82));
        setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(123, 234, 243));
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(224, 114, 82));
        
        setColour(juce::Slider::backgroundColourId, juce::Colour(123, 234, 243));
        setColour(juce::Slider::trackColourId, juce::Colour(224, 114, 82));
        
    }
};

// Custom LookAndFeel, (for categorical sliders)
class CustomLookAndFeelCat : public CustomLookAndFeel
{
    public:
    CustomLookAndFeelCat()
    {
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(123, 234, 243));
        
        setColour(juce::Slider::trackColourId, juce::Colour(123, 234, 243));
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
    
    // 8 Create override for sliderValueChanged
    void sliderValueChanged (juce::Slider* slider) override;
    void toggleNeg();
    void comboBoxChanged (juce::ComboBox* comboBox) override;

private:
    // TODO: Create lables where needed
    
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
    
    // Custom LookAndFeel's
    KnobLookAndFeel knobLookAndFeel;
    CustomLookAndFeel customLookAndFeel;
    CustomLookAndFeelCat customLookAndFeelCat;
    
    
    ModalExplorerVSTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessorEditor)
};
