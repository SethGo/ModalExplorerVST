/*
  ==============================================================================

    MidiProcessor.h
    Created: 21 Feb 2021 10:13:37pm
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MidiProcessor
{
public:
    void process (juce::MidiBuffer& midiMessages, int scale[], int invrsion[])
    {
        processedBuffer.clear();
        processMidiInput (midiMessages);
        midiMessages.swapWith (processedBuffer);
    }
    
    void processMidiInput (const juce::MidiBuffer& midiMessages)
    {
        juce::MidiBuffer::Iterator it (midiMessages);
        juce::MidiMessage currentMessage;
        int samplePos;
        
        while (it.getNextEvent(currentMessage, samplePos))
        {
            if (currentMessage.isNoteOnOrOff())
            {
                // test
                auto transposed = currentMessage;
                transposed.setNoteNumber(50);
                processedBuffer.addEvent (transposed, samplePos);
//                addTransposedNotes (currentMessage, samplePos);
            }
//            processedBuffer.addEvent (currentMessage, samplePos); // Root (user selected midi note)
        }
    }
    
    void addTransposedNotes (juce::MidiMessage currentMessage, int samplePos)
    {
        // test for chord function
        auto transposedMessage  = currentMessage;
        auto oldNoteNum = transposedMessage.getNoteNumber();
        transposedMessage.setNoteNumber (oldNoteNum + 3); // min 3rd
        processedBuffer.addEvent (transposedMessage, samplePos);

        auto transposedMessage2  = currentMessage;
        auto oldNoteNum2 = transposedMessage2.getNoteNumber();
        transposedMessage2.setNoteNumber (oldNoteNum2 + 7); // 5th
        processedBuffer.addEvent (transposedMessage2, samplePos);

        auto transposedMessage3  = currentMessage;
        auto oldNoteNum3 = transposedMessage3.getNoteNumber();
        transposedMessage3.setNoteNumber (oldNoteNum3 + 14); // 9th
        processedBuffer.addEvent (transposedMessage3, samplePos);
    }
    juce::MidiBuffer processedBuffer;
};
