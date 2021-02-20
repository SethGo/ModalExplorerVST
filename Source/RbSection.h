/*
  ==============================================================================

    RbSection.h
    Created: 16 Feb 2021 4:13:10pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class RbSection  : public juce::Component
{
public:
    RbSection();
    ~RbSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void changeRbMode()
    {
        std::string str;
        rbMode = (int)rbKnob.getValue();
        if (rbMode > 0)
        {
            str = std::to_string(rbMode);
        }
        else
        {
            str = "off";
        }
        modeDisplay.setText (str, juce::NotificationType::dontSendNotification);
    }
    
    int rbMode = 0; // Initialize RB mode off

private:
    juce::Label sectionHeading;
    juce::Slider rbKnob;
    juce::Label modeDisplay;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RbSection)
};
