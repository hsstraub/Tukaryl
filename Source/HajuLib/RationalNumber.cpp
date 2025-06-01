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
    if (newDenominator == 0)
    {
        throw new std::invalid_argument("Rational number with zero denominator");
    }

    auto theGcd = std::gcd(newNumerator, newDenominator);
    if (theGcd == 1)
    {
        numerator = newNumerator;
        denominator = newDenominator;
    }
    else
    {
        numerator = newNumerator/theGcd;
        denominator = newDenominator/theGcd;
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

RationalNumber RationalNumber::operator*(RationalNumber const& second) const
{
    return RationalNumber(numerator * second.numerator, denominator * second.denominator);
}

RationalNumber RationalNumber::getInverse() const
{
    return RationalNumber(denominator, numerator);  // Validity check (new denominater != 0) done in constructor
}
