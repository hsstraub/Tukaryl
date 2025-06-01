/*
  ==============================================================================

    RationalNumber.h
    Created: 11 May 2025 10:40:08pm
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class RationalNumber
{
public:
    RationalNumber(int newNumerator, int newDenominator);

    double asDouble() const;
    juce::String asString() const;

    RationalNumber operator*(RationalNumber const& second) const;
    RationalNumber getInverse() const;

private:
    int numerator;
    int denominator;
};

