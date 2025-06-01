/*
  ==============================================================================

    IntervalModel.h
    Created: 11 May 2025 11:33:41am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../HajuLib/RationalNumber.h"

// A pitch frequency, specified  is either as a frequency ratio or as number of cents.
class IntervalModel
{
public:
    IntervalModel(RationalNumber intervalRatio);
    IntervalModel(float valueInCents);

    double getValueInCents() const;
    double getValueAsFrequencyRatio() const;
    juce::String toString();

    IntervalModel add(IntervalModel const& second) const;
    IntervalModel getInverse() const;

    static IntervalModel perfectPrime() { return IntervalModel(RationalNumber(1, 1)); }
    static IntervalModel octave() { return IntervalModel(RationalNumber(2, 1)); }
    static IntervalModel doubleOctave() { return IntervalModel(RationalNumber(4, 1)); }

private:
    std::variant<RationalNumber, float> value;
};

