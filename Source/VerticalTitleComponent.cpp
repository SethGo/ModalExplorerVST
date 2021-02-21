/*
  ==============================================================================

    VerticalTitleComponent.cpp
    Created: 21 Feb 2021 5:10:36am
    Author:  Seth Gory

  ==============================================================================
*/

#include <JuceHeader.h>
#include "VerticalTitleComponent.h"

//==============================================================================
VerticalTitleComponent::VerticalTitleComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

VerticalTitleComponent::~VerticalTitleComponent()
{
}

void VerticalTitleComponent::paint (juce::Graphics& g)
{
    auto area = getLocalBounds();
    g.setColour(juce::Colours::white);
    g.drawRect (area);
    
    g.drawLine(0, getHeight() * 0.35, getWidth(), getHeight() * 0.35);
    
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

void VerticalTitleComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
