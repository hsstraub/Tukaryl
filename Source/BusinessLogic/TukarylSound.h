/*
  ==============================================================================

    TukarylSound.h
    Created: 27 Apr 2025 11:47:35am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]

struct TukarylSound : public juce::SynthesiserSound
{
    TukarylSound() {}
    bool appliesToNote (int) override { return true; }
    bool appliesToChannel (int) override { return true; }
};

