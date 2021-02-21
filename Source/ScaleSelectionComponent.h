/*
  ==============================================================================

    ScaleSelectionComponent.h
    Created: 20 Feb 2021 11:35:58pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ScaleSelectionComponent  : public juce::Component
{
public:
    ScaleSelectionComponent();
    ~ScaleSelectionComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void changeKey();
    void updateScale();
    std::string getAccidental (int sliderVal);
    int getAlterationValue (std::string accidental);
    void changeNote (int scaleDegree);
    
    // Scale control variables
    const int BASE_SCALE[7] = { 0, 2, 4, 5, 7, 9, 11 };
    int scale[7] = { 0, 2, 4, 5, 7, 9, 11 }; // Scale initializes on key of C
    const std::string noteNames[12] = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B" };
    int alterationArray[7];
    bool negHarmOn;

private:
    juce::Label romNum1, romNum2, romNum3, romNum4, romNum5, romNum6, romNum7;
    juce::Slider keyKnob;
    juce::Slider noteAltSlider2, noteAltSlider3, noteAltSlider4, noteAltSlider5, noteAltSlider6, noteAltSlider7;
    juce::Label note1, note2, note3, note4, note5, note6, note7;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleSelectionComponent)
};
