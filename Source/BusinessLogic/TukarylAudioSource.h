/*
  ==============================================================================

    TukarylAudioSource.h
    Created: 27 Apr 2025 11:29:43am
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]

class TukarylAudioSource : public juce::AudioSource
{
public:
    TukarylAudioSource (juce::MidiKeyboardState& keyState);

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

private:
    juce::MidiKeyboardState& keyboardState;
    juce::Synthesiser synth;
};
