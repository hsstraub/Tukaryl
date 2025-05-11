/*
  ==============================================================================

    RationalNumber.cpp
    Created: 11 May 2025 10:40:08pm
    Author:  hsstraub

  ==============================================================================
*/

#include "RationalNumber.h"

RationalNumber::RationalNumber(int newNumerator, int newDenominator)
: numerator(newNumerator), denominator(newDenominator)
{
    if (denominator == 0)
    {
        throw new std::invalid_argument("Rational number with zero denominator");
    }
}

double RationalNumber::asDouble() const
{
    return (double)numerator / (double)denominator;
}

juce::String RationalNumber::asString() const
{
    return juce::String(numerator) + "/" + juce::String(denominator);
}
