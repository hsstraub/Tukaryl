/*
  ==============================================================================

    TukarylInstrument.h
    Created: 13 Apr 2025 7:39:30pm
    Author:  hsstraub

  ==============================================================================
*/

#pragma once
#include "FrequencyModel.h"

struct TukarylInstrument
{
    FrequencyModel baseFrequency = FrequencyModel::perfectPrime();
    unsigned short baseOscLevel;

    FrequencyModel partial1Frequency;
    unsigned short partial1Level;

    TukarylInstrument(
        unsigned short newBaseOscLevel, FrequencyModel newPartial1Frequency, unsigned short newPartial1Level)
    : baseOscLevel(newBaseOscLevel), partial1Frequency(newPartial1Frequency), partial1Level(newPartial1Level)
    {
    }
};
