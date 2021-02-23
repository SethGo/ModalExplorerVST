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
                // if user note is one of these {60, 62, 64, 65, 67, 69, 71}, then do all the code... else do nothing
                
                // translate user note to chord function // noteNum = currentMessage.getNoteNumber() ... getChordFunctionFromUserNote(noteNum)
                
                // use function, scale, and inversion to derive chord // deriveChord()
                
                // displace chord notes by octaves according to voice and get midi note numbers // getMidiNotesFromChord(chord)
                
                // send midi notes and samplePos to processedBuffer, // addEvent()
                
                processedBuffer.addEvent (currentMessage, samplePos);
            }
        }
    }

    int getChordFunctionFromUserNote(int userMidiNote)
    {
        int function;
        switch (userMidiNote) {
            case 60:
                function = 0;
                break;
            case 62:
                function = 1;
                break;
            case 64:
                function = 2;
                break;
            case 65:
                function = 3;
                break;
            case 67:
                function = 4;
                break;
            case 69:
                function = 5;
                break;
            case 71:
                function = 6;
                break;
            default:
                break;
        }
        return function;
    }
    
    void deriveChord(int fucntion, int scale[], int inversion[], int chord[])
    {
        //
    }
    
    void getMidiNotesFromChord(int chord, int midiNotes)
    {
        //
    }
    
    juce::MidiBuffer processedBuffer;
};
