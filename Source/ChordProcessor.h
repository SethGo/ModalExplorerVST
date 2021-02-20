/*
  ==============================================================================

    ChordProcessor.h
    Created: 20 Feb 2021 2:36:55am
    Author:  Seth Gory

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ScaleSection.h"
#include "InversionSection.h"

class ChordProcessor
{
public:
    // define getChord() to return the strings of each note in the chord
    
    // int chord[4] = { 0, 4, 7, 11 }; // Initialize as CMaj7
    
private:
    ScaleSection scale;
    NegHarmSection negHarm;
    RbSection rb;
    InversionSection inv;
};
