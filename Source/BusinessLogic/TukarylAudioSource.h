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

#include "../Model/TukarylInstrument.h"
//[/Headers]

class TukarylAudioSource : public juce::AudioSource, public juce::ChangeListener
{
public:
    TukarylAudioSource (juce::MidiKeyboardState& keyState, TukarylInstrument& tukarylInstrument);

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    void changeListenerCallback(juce::ChangeBroadcaster *source) override;

    juce::MidiMessageCollector* getMidiCollector()
    {
        return &midiCollector;
    }

public:
    const int numberOfVoices = 6;


private:
    juce::MidiKeyboardState& keyboardState;
    juce::Synthesiser synth;
    juce::MidiMessageCollector midiCollector;
};
