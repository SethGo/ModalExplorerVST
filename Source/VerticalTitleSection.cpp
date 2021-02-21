/*
  ==============================================================================

    VerticalTitleSection.cpp
    Created: 16 Feb 2021 6:51:10pm
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "VerticalTitleSection.h"

//==============================================================================
VerticalTitleSection::VerticalTitleSection()
{

}

VerticalTitleSection::~VerticalTitleSection()
{
}

void VerticalTitleSection::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
    
    auto scaleXPos = getHeight() * -0.215f;
    auto voicingXPos = getHeight() * -0.72f;
    float fontSize = getWidth() * 0.42f;
    auto textYPos = (getWidth() + (fontSize / 2)) / 2.0f;
    
    // Vertical text for SCALE and VOICING titles
    g.setColour (juce::Colours::white);
    juce::GlyphArrangement ga;
    ga.addLineOfText (juce::Font (fontSize), "SCALE", scaleXPos, textYPos);
    ga.addLineOfText (juce::Font (fontSize), "VOICING", voicingXPos, textYPos);
    juce::Path p;
    ga.createPath (p);
    p.applyTransform (juce::AffineTransform().rotated (juce::degreesToRadians(-90.0f), 0, 0));
    g.fillPath (p);
}

void VerticalTitleSection::resized()
{

}
