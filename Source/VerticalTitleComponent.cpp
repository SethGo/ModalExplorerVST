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
    g.setColour (juce::Colour(123, 234, 243));
    auto area = getLocalBounds();
    auto scaleSection = area.removeFromTop (getHeight() * 0.45);
    g.drawRoundedRectangle (scaleSection.toFloat().reduced(2), 10, 2);
    g.drawRoundedRectangle (area.toFloat().reduced(2), 10, 2);;
    
    auto scaleXPos = getHeight() * -0.27f;
    auto voicingXPos = getHeight() * -0.79f;
    float fontSize = getWidth() * 0.42f;
    auto textYPos = (getWidth() + (fontSize / 2)) / 2.0f;
    
    // Vertical text for SCALE and VOICING titles
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
