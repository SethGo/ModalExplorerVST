/*
  ==============================================================================

    ScaleSection.h
    Created: 16 Feb 2021 4:12:45pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NegHarmSection.h"
#include "RbSection.h"

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
    
    void updateScale()
    {
        for (int i = 0; i < 7; i++)
        {
            scale[i] = (BASE_SCALE[i] + (int)keyKnob.getValue() + alterationArray[i]) % 12;
        }
        
        note2.setText (noteNames[scale[1]], juce::NotificationType::dontSendNotification);
        note3.setText (noteNames[scale[2]], juce::NotificationType::dontSendNotification);
        note4.setText (noteNames[scale[3]], juce::NotificationType::dontSendNotification);
        note5.setText (noteNames[scale[4]], juce::NotificationType::dontSendNotification);
        note6.setText (noteNames[scale[5]], juce::NotificationType::dontSendNotification);
        note7.setText (noteNames[scale[6]], juce::NotificationType::dontSendNotification);
    }
    
    void changeKey()
    {
        std::string keyString = noteNames [(int)keyKnob.getValue()];
        note1.setText (keyString, juce::dontSendNotification);
        updateScale();
    }
    
    std::string getAccidental (int sliderVal)
    {
        // Get accidental from slider val
        std::string prefix;
        switch (sliderVal) {
            case 0: // Flat
                prefix = "b";
                break;
            case 1: // Natural
                prefix = " ";
                break;
            case 2: // Sharp
                prefix = "#";
                break;
            default:
                break;
        }
        return prefix;
    }
    
    int getAlterationValue (std::string accidental)
    {
        // Get chromatic alteration from accidental
        int alterationValue;
        if (accidental == "b")
        {
            alterationValue = -1;
        }
        else if (accidental == " ")
        {
            alterationValue = 0;
        }
        else
        {
            alterationValue = 1;
        }
        
        return alterationValue;
    }
    
    void changeNote (int scaleDegree)
    {
        std::string accidental;
        switch (scaleDegree) {
            case 1:
                accidental = getAccidental (noteAltSlider2.getValue());
                romNum2.setText (accidental + "II", juce::dontSendNotification);
                alterationArray[1] = getAlterationValue (accidental);
                break;
            case 2:
                accidental = getAccidental (noteAltSlider3.getValue());
                romNum3.setText (accidental + "III", juce::dontSendNotification);
                alterationArray[2] = getAlterationValue (accidental);
                break;
            case 3:
                accidental = getAccidental (noteAltSlider4.getValue());
                romNum4.setText (accidental + "IV", juce::dontSendNotification);
                alterationArray[3] = getAlterationValue (accidental);
                break;
            case 4:
                accidental = getAccidental (noteAltSlider5.getValue());
                romNum5.setText (accidental + "V", juce::dontSendNotification);
                alterationArray[4] = getAlterationValue (accidental);
                break;
            case 5:
                accidental = getAccidental (noteAltSlider6.getValue());
                romNum6.setText (accidental + "VI", juce::dontSendNotification);
                alterationArray[5] = getAlterationValue (accidental);
                break;
            case 6:
                accidental = getAccidental (noteAltSlider7.getValue());
                romNum7.setText (accidental + "VII", juce::dontSendNotification);
                alterationArray[6] = getAlterationValue (accidental);
                break;
            default:
                break;
        }
        updateScale();
    }

    int scale[7] = { 0, 2, 4, 5, 7, 9, 11 }; // Scale initializes on key of C
    
private:
    juce::Label romNum1, romNum2, romNum3, romNum4, romNum5, romNum6, romNum7;
    juce::Slider keyKnob;
    juce::Slider noteAltSlider2, noteAltSlider3, noteAltSlider4, noteAltSlider5, noteAltSlider6, noteAltSlider7;
    juce::Label note1, note2, note3, note4, note5, note6, note7;
    
    // Scale control variables
    int BASE_SCALE[7] = { 0, 2, 4, 5, 7, 9, 11 };
    std::string noteNames[12] = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B" };
    int alterationArray[7];
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleSection)
};
