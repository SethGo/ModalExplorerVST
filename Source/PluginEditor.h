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
            float diameter = width - (outlineThickness + 10); // +10 so outline doesn't get cut off
            float radius = diameter/2;
            float centerX = x + width/2;
            float centerY = y + height /2;
            float rx = centerX - radius;
            float ry = centerY - radius;
            float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
            
            juce::Rectangle<float> knobArea (rx, ry, diameter, diameter);
            g.setColour(juce::Colour(123, 234, 243));
//            g.drawRect(knobArea);
            g.fillEllipse(knobArea);
            
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
                                              // 7 Add any component listeners such as...
                                              public juce::Slider::Listener
//                                              public juce::TextButton::Listener
{
public:
    ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor&);
    ~ModalExplorerVSTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    // 8 Create override for sliderValueChanged
    void sliderValueChanged (juce::Slider* slider) override;

private:
    // 1 instantiate the object
    // Key knob
    juce::Slider keyKnob;
    
    // Note alteration sliders
    juce::Slider noteAltSlider2;
    juce::Slider noteAltSlider3;
    juce::Slider noteAltSlider4;
    juce::Slider noteAltSlider5;
    juce::Slider noteAltSlider6;
    juce::Slider noteAltSlider7;
    
    // Negative harmony button TextButton
//    enum class NegState
//    {
//        On,
//        Off
//    };
//    
//    NegState negState { NegState::Off };
//    juce::TextButton negHarmBtn { "Off" };
    
    // RB mode knob
    
    // Glide
    juce::Slider glideSlider;
    
    // Inversion knobs
    juce::Slider invKnobS;
    juce::Slider invKnobA;
    juce::Slider invKnobT;
    juce::Slider invKnobB;
    
    // Oscillator waveform selection knobs
    
    // Oscillator mix sliders
    
    // Filter ADSR
    
    // Cutoff and resonance rotary sliders
    
    // Output knob
    
    // Custom LookAndFeel's
    KnobLookAndFeel knobLookAndFeel;
    CustomLookAndFeel customLookAndFeel;
    CustomLookAndFeelCat customLookAndFeelCat;
    
    
    ModalExplorerVSTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessorEditor)
};
