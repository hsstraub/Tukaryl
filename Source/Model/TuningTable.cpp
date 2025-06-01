/*
  ==============================================================================

    TuningTable.cpp
    Created: 1 Jun 2025 10:15:33am
    Author:  hsstraub

  ==============================================================================
*/

#include "TuningTable.h"

TuningTable TuningTable::standard12Edo()
{
    TuningTable tuningTable;

    tuningTable.push_back(IntervalModel(100.0));
    tuningTable.push_back(IntervalModel(200.0));
    tuningTable.push_back(IntervalModel(300.0));
    tuningTable.push_back(IntervalModel(400.0));
    tuningTable.push_back(IntervalModel(500.0));
    tuningTable.push_back(IntervalModel(600.0));
    tuningTable.push_back(IntervalModel(700.0));
    tuningTable.push_back(IntervalModel(800.0));
    tuningTable.push_back(IntervalModel(900.0));
    tuningTable.push_back(IntervalModel(1000.0));
    tuningTable.push_back(IntervalModel(1100.0));
    tuningTable.push_back(IntervalModel(RationalNumber(2, 1)));

    return tuningTable;
}
