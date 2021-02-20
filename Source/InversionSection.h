/*
  ==============================================================================

    InversionSection.h
    Created: 16 Feb 2021 4:13:50pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class InversionSection  : public juce::Component
{
public:
    InversionSection();
    ~InversionSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void changeVoice (int voice)
    {
        int knobVal;
        std::string str;
        switch (voice) {
            case 0:
                knobVal = (int)invKnobB.getValue();
                voicingArray[0] = knobVal;
                str = (knobVal > 0) ? std::to_string(knobVal) : "off";
                invLabelB.setText (str, juce::NotificationType::dontSendNotification);
                break;
            case 1:
                knobVal = (int)invKnobT.getValue();
                voicingArray[1] = knobVal;
                str = (knobVal > 0) ? std::to_string(knobVal) : "off";
                invLabelT.setText (str, juce::NotificationType::dontSendNotification);
                break;
            case 2:
                knobVal = (int)invKnobA.getValue();
                voicingArray[2] = knobVal;
                str = (knobVal > 0) ? std::to_string(knobVal) : "off";
                invLabelA.setText (str, juce::NotificationType::dontSendNotification);
                break;
            case 3:
                knobVal = (int)invKnobS.getValue();
                voicingArray[3] = knobVal;
                str = (knobVal > 0) ? std::to_string(knobVal) : "off";
                invLabelS.setText (str, juce::NotificationType::dontSendNotification);
                break;
            default:
                break;
        }
    }

    int voicingArray[4] = { 1, 3, 5, 7 };
    
private:
    juce::Label sectionHeading;
    juce::Slider invKnobS, invKnobA, invKnobT, invKnobB;
    juce::Label invLabelS, invLabelA, invLabelT, invLabelB;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InversionSection)
};
