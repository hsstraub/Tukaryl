#pragma once

#include <JuceHeader.h>

#include "View/TukarylSoundEdit.h"
#include "Model/TukarylInstrument.h"
#include "HajuLib/HajuMidiDriver.h"
#include "BusinessLogic/TukarylAudioSource.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    void setMidiInput (int index);

    //==============================================================================
    // Your private member variables go here...
    TukarylInstrument            theInstrument;

    HajuMidiDriver			     midiDriver;
    juce::MidiKeyboardState      keyboardState;
    TukarylAudioSource           theAudioSource;

    std::unique_ptr<juce::ComboBox> cbMidiInput;
    std::unique_ptr<TukarylSoundEdit> soundEditComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
