/*
  ==============================================================================

    NegHarmSection.h
    Created: 16 Feb 2021 4:12:54pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class NegHarmSection  : public juce::Component
{
public:
    NegHarmSection();
    ~NegHarmSection() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void toggleNegHarm()
    {
        negHarmOn = !negHarmOn;
        negHarmBtn.setToggleState (negHarmOn, juce::NotificationType::dontSendNotification);
        if (negHarmOn)
        {
            negHarmBtn.setButtonText ("on");
        }
        else
        {
            negHarmBtn.setButtonText ("off");
        }
    }
    
    bool negHarmOn = false; // Initialize false

private:
    juce::TextButton negHarmBtn;
    juce::Label sectionHeading;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NegHarmSection)
};
