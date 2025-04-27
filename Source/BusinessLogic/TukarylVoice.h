/*
  ==============================================================================

    TukarylVoice.h
    Created: 27 Apr 2025 11:59:36am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

#include "../Model/TukarylInstrument.h"
//[/Headers]

class TukarylVoice : public juce::SynthesiserVoice
{
public:
    TukarylVoice(TukarylInstrument& tukarylInstrument);

    bool canPlaySound(juce::SynthesiserSound* sound) override;

    void startNote(
        int midiNoteNumber, float velocity, juce::SynthesiserSound*, int /*currentPitchWheelPosition*/) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved (int) override      {}
    void controllerMoved (int, int) override {}

    void renderNextBlock (juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

    void updateFromInstrument();

private:
    TukarylInstrument& theInstrument;

    double currentBaseFrequency = 440.0;
    double currentVelocity = 0.0;

    double currentAngle1 = 0.0, angleDelta1 = 0.0;
    double currentAngle2 = 0.0, angleDelta2 = 0.0;
};
