/*
  ==============================================================================

    ScaleSection.h
    Created: 16 Feb 2021 4:12:45pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ScaleSection  : public juce::Component
{
public:
    ScaleSection();
    ~ScaleSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Label romNum1, romNum2, romNum3, romNum4, romNum5, romNum6, romNum7;
    juce::Slider keyKnob;
    juce::Slider noteAltSlider2, noteAltSlider3, noteAltSlider4, noteAltSlider5, noteAltSlider6, noteAltSlider7;
    juce::Label note1, note2, note3, note4, note5, note6, note7;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleSection)
};
