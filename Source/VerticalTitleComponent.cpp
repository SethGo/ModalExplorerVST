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
    g.drawRoundedRectangle (area.toFloat().reduced(2), 10, 2);
    
    auto textXPos = getHeight() * -0.66;
    float fontSize = 25.0f;
    auto textYPos = (getWidth() + (fontSize / 2)) / 2.0f;
    
    // Vertical text for SCALE and VOICING titles
    juce::GlyphArrangement ga;
    ga.addLineOfText (juce::Font (fontSize), verticalTitle, textXPos, textYPos);
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

void VerticalTitleComponent::setVerticalTitle (std::string title)
{
    verticalTitle = title;
}
