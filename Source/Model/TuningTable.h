/*
  ==============================================================================

    TuningTable.h
    Created: 1 Jun 2025 10:15:33am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

#include "IntervalModel.h"

class TuningTable : public std::vector<IntervalModel>
{
public:
    IntervalModel periodInterval() const { return*(--end()); }

    String getDescription() const { return description; }
    void setDescription(String value) { description = value; }

    static TuningTable standard12Edo();

private:
    String description;
};

