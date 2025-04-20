#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    theInstrument = TukarylInstrument {
        1.0,
        63,
        2.0,
        31,
    };

    // Make sure you set the size of the component after
    // you add any child components.

    soundEditComponent.reset (new TukarylSoundEdit(theInstrument));
    addAndMakeVisible(soundEditComponent.get());
    soundEditComponent->setBounds(0, 40, 600, 400);
    soundEditComponent->addChangeListener(this);

    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (0, 2);
    }
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
    currentSampleRate = sampleRate;
    changeListenerCallback(nullptr);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
        auto level1 = ((float)theInstrument.baseOscLevel)/1000.0f;
        auto level2 = ((float)theInstrument.partial1Level)/1000.0f;

        auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
        auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);

        for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            auto currentSample1 = (float) std::sin (currentAngle1);
            currentAngle1 += angleDelta1;

            auto currentSample2 = (float) std::sin (currentAngle2);
            currentAngle2 += angleDelta2;

            leftBuffer[sample]  = currentSample1 * level1 + currentSample2 * level2;
            rightBuffer[sample] = currentSample1 * level1 + currentSample2 * level2;
        }
 }

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
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
}

void MainComponent::changeListenerCallback(juce::ChangeBroadcaster *source)
{
    if (currentSampleRate > 0.0)
    {
        auto basefrequency = 440.0;   // Ad hoc frequency fix 440 Hz

        auto cyclesPerSample1 = basefrequency / currentSampleRate;
        angleDelta1 = cyclesPerSample1 * 2.0 * juce::MathConstants<double>::pi;

        auto cyclesPerSample2 = basefrequency * theInstrument.partial1Frequency / currentSampleRate;
        angleDelta2 = cyclesPerSample2 * 2.0 * juce::MathConstants<double>::pi;
   }
}

