/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "VerticalTitleSection.h"
#include "ScaleSection.h"
#include "NegHarmSection.h"
#include "RbSection.h"
#include "OutputLevelSection.h"
#include "InversionSection.h"
#include "ChordSection.h"
#include "MixSection.h"
#include "ChordProcessor.h"

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
    VerticalTitleSection verticalTitleSection;
    ScaleSection scaleSection;
    NegHarmSection negHarmSection;
    RbSection rbSection;
    OutputLevelSection outputLevelSection;
    InversionSection inversionSection;
    ChordSection chordSection;
    MixSection mixSection;
    
    ModalExplorerVSTAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModalExplorerVSTAudioProcessorEditor)
};
