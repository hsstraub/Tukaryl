/*
  ==============================================================================

    TukarylInstrument.h
    Created: 13 Apr 2025 7:39:30pm
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

struct TukarylInstrument
{
    double baseFrequency = 1.0;
    unsigned short baseOscLevel;

    double partial1Frequency;
    unsigned short partial1Level;
};
