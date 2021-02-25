/*
  ==============================================================================

    LooksAndFeels.h
    Created: 25 Feb 2021 1:25:34am
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

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
        
        // TextButton settings
        setColour (juce::TextButton::textColourOffId, brightBlue);
        setColour (juce::TextButton::textColourOnId, darkBlue);
        setColour (juce::TextButton::buttonColourId, darkBlue);
        setColour (juce::TextButton::buttonOnColourId, brightBlue);
        
        // Label settings
        setColour (juce::Label::ColourIds::textColourId, orangePastel);
    }
};

class BlueTextLookAndFeel : public CustomLookAndFeel
{
public:
    BlueTextLookAndFeel()
    {
        // Label settings
        setColour (juce::Label::ColourIds::textColourId, juce::Colour(123, 234, 243));
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

