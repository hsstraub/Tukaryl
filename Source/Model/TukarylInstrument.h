/*
  ==============================================================================

    TukarylInstrument.h
    Created: 13 Apr 2025 7:39:30pm
    Author:  hsstraub

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "IntervalModel.h"
#include "TuningTable.h"

struct TukarylInstrument
{
    IntervalModel baseFrequency = IntervalModel::perfectPrime();
    unsigned short baseOscLevel;

    IntervalModel partial1Frequency;
    unsigned short partial1Level;

    IntervalModel partial2Frequency;
    unsigned short partial2Level;

    IntervalModel partial3Frequency;
    unsigned short partial3Level;

    IntervalModel partial4Frequency;
    unsigned short partial4Level;

    TuningTable tuningTable = TuningTable::standard12Edo();

    ADSR::Parameters mainEnvelope = ADSR::Parameters(0.1f, 0.1f, 1.0f, 0.1f);

    TukarylInstrument(
        unsigned short newBaseOscLevel,
        IntervalModel newPartial1Frequency,
        unsigned short newPartial1Level,
        IntervalModel newPartial2Frequency,
        unsigned short newPartial2Level,
        IntervalModel newPartial3Frequency,
        unsigned short newPartial3Level,
        IntervalModel newPartial4Frequency,
        unsigned short newPartial4Level,
        TuningTable newTuningTable,
        ADSR::Parameters newMainEnvelope)
    : baseOscLevel(newBaseOscLevel)
    , partial1Frequency(newPartial1Frequency)
    , partial1Level(newPartial1Level)
    , partial2Frequency(newPartial2Frequency)
    , partial2Level(newPartial2Level)
    , partial3Frequency(newPartial3Frequency)
    , partial3Level(newPartial3Level)
    , partial4Frequency(newPartial4Frequency)
    , partial4Level(newPartial4Level)
    , tuningTable(newTuningTable)
    , mainEnvelope(newMainEnvelope)
    {
    }
};
