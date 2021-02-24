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
    void process (juce::MidiBuffer& midiMessages, int scale[], int inversion[], float velocities[])
    {
        processedBuffer.clear();
        processMidiInput (midiMessages, scale, inversion, velocities);
        midiMessages.swapWith (processedBuffer);
    }
    
    void processMidiInput (const juce::MidiBuffer& midiMessages, int scale[], int inversion[], float velocities[])
    {
        juce::MidiBuffer::Iterator it (midiMessages);
        juce::MidiMessage currentMessage;
        int samplePos;
        
        while (it.getNextEvent (currentMessage, samplePos))
        {
            int userMidiNoteNum = currentMessage.getNoteNumber();
            if (userSelectedAvailableNote (userMidiNoteNum))
            {
                int chordNotes[4];
                int chordMidiNotes[4] = { 0, 0, 0, 0 };
                int function = getChordFunctionFromUserNote (userMidiNoteNum);
                deriveChord (function, scale, inversion, chordNotes);
                getMidiNotesFromChord (chordNotes, chordMidiNotes);
                addChordToMidiBuffer (currentMessage, chordMidiNotes, velocities, samplePos);
            }
        }
    }
    
    bool userSelectedAvailableNote (int userNote)
    {
        const int availableNotes[7] = { 60, 62, 64, 65, 67, 69, 71 }; // White keys starting on middle C
        for (int i = 0; i < 7; i++)
        {
            if (userNote == availableNotes[i])
            {
                return true;
            }
        }
        return false;
    }

    int getChordFunctionFromUserNote (int userMidiNoteNum)
    {
        int function;
        switch (userMidiNoteNum) {
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
    
    void deriveChord (int function, int scale[], int inversion[], int chordNotes[])
    {
        for (int i = 0; i < 4; i++)
        {
            if (inversion[i] != 0)
            {
                int scaleIndex = (inversion[i] - 1 + function) % 7;
                chordNotes[i] = (scale[scaleIndex]);
            }
            else
            {
                chordNotes[i] = 12; // note '12' will turn this voice off
            }
        }
    }
    
    void getMidiNotesFromChord (int chordNotes[], int chordMidiNotes[])
    {
        for (int i = 0; i < 4; i++)
        {
            if (chordNotes[i] < 12)
            {
                chordMidiNotes[i] = chordNotes[i] + 48 + 12 * i;
            }
            else
            {
                chordMidiNotes[i] = 0;
            }
        }
    }
    
    void addChordToMidiBuffer (juce::MidiMessage currentMessage, int chordMidiNotes[], float velocities[], int samplePos)
    {
        if (chordMidiNotes[0] > 0)
        {
            auto bassMidiMessage  = currentMessage;
            bassMidiMessage.setNoteNumber (chordMidiNotes[0]);
            bassMidiMessage.setVelocity (velocities[0]);
            processedBuffer.addEvent (bassMidiMessage, samplePos);
        }
        
        if (chordMidiNotes[1] > 0)
        {
            auto tenorMidiMessage  = currentMessage;
            tenorMidiMessage.setNoteNumber (chordMidiNotes[1]);
            tenorMidiMessage.setVelocity (velocities[1]);
            processedBuffer.addEvent (tenorMidiMessage, samplePos);
        }
           
        if (chordMidiNotes[2] > 0)
        {
            auto altoMidiMessage  = currentMessage;
            altoMidiMessage.setNoteNumber (chordMidiNotes[2]);
            altoMidiMessage.setVelocity (velocities[2]);
            processedBuffer.addEvent (altoMidiMessage, samplePos);
        }
        
        if (chordMidiNotes[3] > 0)
        {
            auto sopranoMidiMessage  = currentMessage;
            sopranoMidiMessage.setNoteNumber (chordMidiNotes[3]);
            sopranoMidiMessage.setVelocity (velocities[3]);
            processedBuffer.addEvent (sopranoMidiMessage, samplePos);
        }
    }
    
    juce::MidiBuffer processedBuffer;
};
