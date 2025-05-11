/*
  ==============================================================================

    HajuMidiDriver.h
    Created: 23 Feb 2018 11:30:58pm
    Author:  hsstraub

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]


/*
==============================================================================
Driver encapsulating MIDI functionality, extension of JUCE
==============================================================================
*/
class HajuMidiDriver
{
public:
	HajuMidiDriver();
	~HajuMidiDriver();

	// List of MIDI input device names
	juce::StringArray getMidiInputList();

	// List of MIDI output device names
	juce::StringArray getMidiOutputList();

	// Open the specified input device
	void setMidiInput(int deviceIndex, juce::MidiInputCallback* callback);

	// Open the specified output device
	void setMidiOutput(int deviceIndex);

	int getFirstEnabledMidiInput();

	void setFirstEnabledMidiInput(MidiInputCallback* callback);

	// Send a MIDI message directly
	void sendMessageNow(const juce::MidiMessage& message);

	// Higher level commands
	void sendNoteOnMessage(int noteNumber, int channelNumber, uint8 velocity);
	void sendNoteOffMessage(int noteNumber, int channelNumber, uint8 velocity);


	// Attributes
protected:
	Array<MidiDeviceInfo> midiInputs;
	Array<MidiDeviceInfo> midiOutputs;
	AudioDeviceManager deviceManager;

	int lastInputIndex = -1;
	MidiInputCallback* lastInputCallback = nullptr;

	// Currently open MIDI output
  std::unique_ptr<MidiOutput> midiOutput = nullptr;
};
