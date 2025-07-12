#include "MainComponent.h"
#include "View/ViewConstants.h"

//==============================================================================
MainComponent::MainComponent()
: theInstrument(
    63,
    IntervalModel::octave(),
    31,
    IntervalModel(RationalNumber(3, 1)),
    15,
    IntervalModel(RationalNumber(4, 1)),
    7,
    IntervalModel(RationalNumber(5, 1)),
    5,
    TuningTable::standard12Edo(),
    ADSR::Parameters(0.1f, 0.1f, 1.0f, 0.1f))
, theAudioSource(keyboardState, theInstrument)
{
    // Make sure you set the size of the component after
    // you add any child components.

    cbMidiInput.reset (new juce::ComboBox ("cbMidiInput"));
    addAndMakeVisible (cbMidiInput.get());
    cbMidiInput->setTooltip (TRANS ("Receives answers to sent SysEx commands and the current configuration from controller "));
    cbMidiInput->setEditableText (false);
    cbMidiInput->setJustificationType (juce::Justification::centredLeft);
    cbMidiInput->setTextWhenNothingSelected (TRANS ("Select MIDI Input"));
    cbMidiInput->setTextWhenNoChoicesAvailable (TRANS ("(no choices)"));
    cbMidiInput->addItemList(midiDriver.getMidiInputList(), 1);
    cbMidiInput->onChange = [this] { setMidiInput (cbMidiInput->getSelectedItemIndex()); };
    cbMidiInput->setBounds (8, MIDIINPUTTOP, 184, 24);

    soundEditComponent.reset (new TukarylSoundEdit(theInstrument));
    addAndMakeVisible(soundEditComponent.get());
    soundEditComponent->addChangeListener(&theAudioSource);
    soundEditComponent->setBounds(0, SOUNDEDITTOP, 600, 400);

    setSize (800, 600);

    // Specify the number of input and output channels that we want to open
    setAudioChannels (0, 2);

    cbMidiInput->setSelectedId(midiDriver.getFirstEnabledMidiInput());
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
    theAudioSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    theAudioSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
    theAudioSource.releaseResources();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    soundEditComponent->setBounds(soundEditComponent->getX(), soundEditComponent->getY(), getWidth(), getHeight() - SOUNDEDITTOP);;
}

void MainComponent::setMidiInput (int index)
{
    if (index >= 0)
        midiDriver.setMidiInput(index, theAudioSource.getMidiCollector());
}

