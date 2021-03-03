/*
  ==============================================================================

    VerticalTitleComponent.h
    Created: 21 Feb 2021 5:10:36am
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class VerticalTitleComponent  : public juce::Component
{
public:
    VerticalTitleComponent();
    ~VerticalTitleComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    std::string verticalTitle;
    void setVerticalTitle (std::string title);


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VerticalTitleComponent)
};
