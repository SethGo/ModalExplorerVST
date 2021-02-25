/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "VerticalTitleComponent.h"
#include "ScaleSelectionComponent.h"
#include "NegHarmComponent.h"
#include "RbComponent.h"
#include "OutputComponent.h"
#include "InversionComponent.h"
#include "MixComponent.h"
#include "LooksAndFeels.h"

//==============================================================================
/**
*/
class ModalExplorerVSTAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ModalExplorerVSTAudioProcessorEditor (ModalExplorerVSTAudioProcessor&);
    ~ModalExplorerVSTAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    InversionComponent inversionComponent;
    ScaleSelectionComponent scaleSelectionComponent;
    NegHarmComponent negHarmComponent;
    RbComponent rbComponent;
    VerticalTitleComponent verticalTitleComponent;
    OutputComponent outputComponent;
    MixComponent mixComponent;
    
    ModalExplorerVSTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessorEditor)
};
