/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "ViewConstants.h"
#include "../BusinessLogic/ScalaSerializer.h"
//[/Headers]

#include "TukarylSoundEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TukarylSoundEdit::TukarylSoundEdit (TukarylInstrument& injectedInstrument)
    : theInstrument(injectedInstrument), errorVisualizer(getLookAndFeel())
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupOscillators.reset (new juce::GroupComponent ("groupOscillators",
                                                      TRANS ("Oscillators")));
    addAndMakeVisible (groupOscillators.get());
    groupOscillators->setTextLabelPosition (juce::Justification::centred);

    osc1.reset (new OscSubComponent (theInstrument.baseFrequency, theInstrument.baseOscLevel, false));
    addAndMakeVisible (osc1.get());
    osc1->setName ("osc1");

    osc1->setBounds (16, 88, 62, 200);

    osc2.reset (new OscSubComponent (theInstrument.partial1Frequency, theInstrument.partial1Level, true));
    addAndMakeVisible (osc2.get());
    osc2->setName ("osc2");

    osc2->setBounds (88, 88, 62, 200);

    lblTuningDescription.reset (new juce::Label ("lblTuningDescription",
                                                 TRANS ("Tuning description")));
    addAndMakeVisible (lblTuningDescription.get());
    lblTuningDescription->setFont (juce::Font (12.00f, juce::Font::plain));
    lblTuningDescription->setJustificationType (juce::Justification::centredLeft);
    lblTuningDescription->setEditable (false, false, false);
    lblTuningDescription->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    lblTuningDescription->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    btnLoadScalaFile.reset (new juce::TextButton ("btnLoadScalaFile"));
    addAndMakeVisible (btnLoadScalaFile.get());
    btnLoadScalaFile->setButtonText (TRANS ("Scala file"));
    btnLoadScalaFile->addListener (this);

    btnLoadScalaFile->setBounds (240, 0, 150, 24);

    btnTuningReset.reset (new juce::TextButton ("btnTuningReset"));
    addAndMakeVisible (btnTuningReset.get());
    btnTuningReset->setButtonText (TRANS ("Reset tuning"));
    btnTuningReset->addListener (this);

    btnTuningReset->setBounds (400, 0, 150, 24);

    labelMessageArea.reset (new juce::Label ("labelMessageArea",
                                             TRANS ("Message area\n")));
    addAndMakeVisible (labelMessageArea.get());
    labelMessageArea->setFont (juce::Font (15.00f, juce::Font::plain));
    labelMessageArea->setJustificationType (juce::Justification::centredLeft);
    labelMessageArea->setEditable (false, false, false);
    labelMessageArea->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelMessageArea->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    groupMainEnvelope.reset (new juce::GroupComponent ("groupMainEnvelope",
                                                       TRANS ("Main output envelope")));
    addAndMakeVisible (groupMainEnvelope.get());

    groupMainEnvelope->setBounds (8, 304, 288, 190);

    mainEnvelopeComponent.reset (new EnvelopeEdit (theInstrument.mainEnvelope.attack, theInstrument.mainEnvelope.decay, theInstrument.mainEnvelope.sustain, theInstrument.mainEnvelope.release));
    addAndMakeVisible (mainEnvelopeComponent.get());
    mainEnvelopeComponent->setName ("mainEnvelopeComponent");

    mainEnvelopeComponent->setBounds (24, 320, 254, 160);

    osc3.reset (new OscSubComponent (theInstrument.partial2Frequency, theInstrument.partial2Level, true));
    addAndMakeVisible (osc3.get());
    osc3->setName ("osc3");

    osc3->setBounds (160, 88, 62, 200);

    osc4.reset (new OscSubComponent (theInstrument.partial3Frequency, theInstrument.partial3Level, true));
    addAndMakeVisible (osc4.get());
    osc4->setName ("osc4");

    osc4->setBounds (232, 88, 62, 200);

    osc5.reset (new OscSubComponent (theInstrument.partial4Frequency, theInstrument.partial4Level, true));
    addAndMakeVisible (osc5.get());
    osc5->setName ("osc5");

    osc5->setBounds (304, 88, 62, 200);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (608, 400);


    //[Constructor] You can add your own custom stuff here..
    osc2->addListener(this);
    osc3->addListener(this);
    osc4->addListener(this);
    osc5->addListener(this);
    //[/Constructor]
}

TukarylSoundEdit::~TukarylSoundEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupOscillators = nullptr;
    osc1 = nullptr;
    osc2 = nullptr;
    lblTuningDescription = nullptr;
    btnLoadScalaFile = nullptr;
    btnTuningReset = nullptr;
    labelMessageArea = nullptr;
    groupMainEnvelope = nullptr;
    mainEnvelopeComponent = nullptr;
    osc3 = nullptr;
    osc4 = nullptr;
    osc5 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TukarylSoundEdit::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    paintRuler(g);

    lblTuningDescription->setText(theInstrument.tuningTable.getDescription(), NotificationType::dontSendNotification);

    auto oscYPos = groupOscillators->getY() + OSCPADTOP;

    osc1->setTopLeftPosition(getXPosOfFrequency(IntervalModel::perfectPrime()) - osc1->getWidth() / 2, oscYPos);
    osc2->setTopLeftPosition(getXPosOfFrequency(theInstrument.partial1Frequency) - osc2->getWidth() / 2, oscYPos);
    osc3->setTopLeftPosition(getXPosOfFrequency(theInstrument.partial2Frequency) - osc3->getWidth() / 2, oscYPos);
    osc4->setTopLeftPosition(getXPosOfFrequency(theInstrument.partial3Frequency) - osc4->getWidth() / 2, oscYPos);
    osc5->setTopLeftPosition(getXPosOfFrequency(theInstrument.partial4Frequency) - osc5->getWidth() / 2, oscYPos);
    //[/UserPaint]
}

void TukarylSoundEdit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    // auto area = getLocalBounds();
    //[/UserPreResize]

    groupOscillators->setBounds (8, 32, proportionOfWidth (0.9777f), 263);
    lblTuningDescription->setBounds (8, 0, 200, 24);
    labelMessageArea->setBounds (0, getHeight() - 16, proportionOfWidth (1.0000f), 16);
    //[UserResized] Add your own custom resize handling here..
    // labelMessageArea->setBounds(area.removeFromBottom (16));
    //[/UserResized]
}

void TukarylSoundEdit::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == btnLoadScalaFile.get())
    {
        //[UserButtonCode_btnLoadScalaFile] -- add your button handler code here..
        OpenSclFileDialog();
        //[/UserButtonCode_btnLoadScalaFile]
    }
    else if (buttonThatWasClicked == btnTuningReset.get())
    {
        //[UserButtonCode_btnTuningReset] -- add your button handler code here..
        displayMessage("Tuning reset to 12edo.", HajuErrorVisualizer::ErrorLevel::noError);
        theInstrument.tuningTable = TuningTable::standard12Edo();
        sendChangeMessage();
        repaint();
        //[/UserButtonCode_btnTuningReset]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TukarylSoundEdit::addChangeListener (juce::ChangeListener* const listener)
{
    ChangeBroadcaster::addChangeListener(listener);
    osc1->addChangeListener(listener);
    osc2->addChangeListener(listener);
    osc3->addChangeListener(listener);
    osc4->addChangeListener(listener);
    osc5->addChangeListener(listener);
    mainEnvelopeComponent->addChangeListener(listener);
}

void TukarylSoundEdit::OnDrag(OscSubComponent* component)
{
    if (component == osc2.get())
    {
        auto dragStart = getLocalPoint(this, component->getDragStart());
        auto dragEnd = getLocalPoint(this, component->getDragEnd());
        auto displacement = dragEnd.getX() - dragStart.getX();

        auto oscWidth = osc2->getWidth();

        double newLeftPos = osc2->getX() + displacement;
        if (newLeftPos <= osc1->getRight())
        {
            newLeftPos = osc1->getRight() + 1;
        }
        else if (newLeftPos >= osc3->getX() - oscWidth)
        {
            newLeftPos = osc3->getX() - oscWidth - 1;
        }

        osc2->setFrequency(getFrequencyOfXPos(newLeftPos + oscWidth / 2));
        repaint();
    }
    else if (component == osc3.get())
    {
        auto dragStart = getLocalPoint(this, component->getDragStart());
        auto dragEnd = getLocalPoint(this, component->getDragEnd());
        auto displacement = dragEnd.getX() - dragStart.getX();

        auto oscWidth = osc3->getWidth();

        double newLeftPos = osc3->getX() + displacement;
        if (newLeftPos <= osc2->getRight())
        {
            newLeftPos = osc2->getRight() + 1;
        }
        else if (newLeftPos >= osc4->getX() - oscWidth)
        {
            newLeftPos = osc4->getX() - oscWidth - 1;
        }

        osc3->setFrequency(getFrequencyOfXPos(newLeftPos + oscWidth / 2));
        repaint();
    }
    else if (component == osc4.get())
    {
        auto dragStart = getLocalPoint(this, component->getDragStart());
        auto dragEnd = getLocalPoint(this, component->getDragEnd());
        auto displacement = dragEnd.getX() - dragStart.getX();

        auto oscWidth = osc4->getWidth();

        double newLeftPos = osc4->getX() + displacement;
        if (newLeftPos <= osc3->getRight())
        {
            newLeftPos = osc3->getRight() + 1;
        }
        else if (newLeftPos >= osc5->getX() - oscWidth)
        {
            newLeftPos = osc5->getX() - oscWidth - 1;
        }

        osc4->setFrequency(getFrequencyOfXPos(newLeftPos + oscWidth / 2));
        repaint();
    }
    else if (component == osc5.get())
    {
        auto dragStart = getLocalPoint(this, component->getDragStart());
        auto dragEnd = getLocalPoint(this, component->getDragEnd());
        auto displacement = dragEnd.getX() - dragStart.getX();

        auto thisWidth = getWidth();
        auto oscWidth = osc5->getWidth();

        double newLeftPos = osc5->getX() + displacement;
        if (newLeftPos <= osc4->getRight())
        {
            newLeftPos = osc4->getRight() + 1;
        }
        else if (newLeftPos >= thisWidth - oscWidth)
        {
            newLeftPos = thisWidth - oscWidth - 1;
        }

        osc5->setFrequency(getFrequencyOfXPos(newLeftPos + oscWidth / 2));
        repaint();
    }
}

void TukarylSoundEdit::paintRuler(juce::Graphics& g)
{
    auto rulerYPos = groupOscillators->getY() + RULERPADFROMTOP;

    g.setColour(getLookAndFeel().findColour(juce::TextEditor::textColourId));
    g.drawLine(groupOscillators-> getX(), rulerYPos, groupOscillators->getRight(), rulerYPos);

    auto baseInterval = IntervalModel::perfectPrime();

    while (baseInterval < maxFrequency)
    {
        paintRulerMark(g, rulerYPos, baseInterval);

        for (auto freqIter = theInstrument.tuningTable.begin(); freqIter != theInstrument.tuningTable.end(); freqIter++)
        {
            auto currentInterval = baseInterval.add(*freqIter);
            if (currentInterval > maxFrequency)
            {
                break;
            }

            paintRulerMark(g, rulerYPos, currentInterval);
        }

        baseInterval = baseInterval.add(theInstrument.tuningTable.periodInterval());
    }
}

void TukarylSoundEdit::paintRulerMark(juce::Graphics& g, int rulerYPos, IntervalModel frequency)
{
    auto xPos = getXPosOfFrequency(frequency);
    if (xPos >= 0 && xPos <= getWidth())
    {
        g.setColour(getLookAndFeel().findColour(juce::TextEditor::textColourId));
        g.setFont(RULERTEXTSIZE);

        auto oscWidth = osc2->getWidth();

        g.drawLine(xPos, rulerYPos, xPos, rulerYPos - RULERMARKHEIGHT);
        g.drawText(frequency.toString(), xPos - oscWidth/2, rulerYPos - RULERMARKHEIGHT- RULERTEXTSIZE - 1, oscWidth, RULERTEXTSIZE, juce::Justification::centred);
    }
}

int TukarylSoundEdit::getXPosOfFrequency(IntervalModel frequency)
{
    auto leftXPos = groupOscillators->getX() + OSCHORIZMARGIN;
    auto width = groupOscillators->getWidth();
    return leftXPos + (width - 2 * OSCHORIZMARGIN) * frequency.getValueInCents() / maxFrequency.getValueInCents();
}

IntervalModel TukarylSoundEdit::getFrequencyOfXPos(double xPos)
{
    auto leftXPos = groupOscillators->getX() + OSCHORIZMARGIN;
    auto width = groupOscillators->getWidth();
    return IntervalModel(
        maxFrequency.getValueInCents() * (xPos - leftXPos) / (width- 2 * OSCHORIZMARGIN));
}

void TukarylSoundEdit::OpenSclFileDialog()
{
    chooser = std::make_unique<FileChooser>("Open a Scala file", File(), "*.scl", true, false, this);
    chooser->launchAsync(FileBrowserComponent::FileChooserFlags::canSelectFiles | FileBrowserComponent::FileChooserFlags::openMode,
        [&](const FileChooser& chooser)
        {
            currentFile = chooser.getResult();
            if ( !currentFile.existsAsFile())
            {
                displayMessage(
                    "The file " + currentFile.getFullPathName() + " could not be opened.",
                    HajuErrorVisualizer::ErrorLevel::error);
            }
            else {
                StringArray stringArray;
                currentFile.readLines(stringArray);

                TuningTable newTuningTable;
                auto deserializationResult = ScalaSerializer::deserialize(stringArray, newTuningTable);

                HajuErrorVisualizer::ErrorLevel errorLevel;
                if (ScalaSerializer::deserializationResultIsError(deserializationResult))
                {
                    errorLevel = HajuErrorVisualizer::ErrorLevel::error;
                }
                else if (deserializationResult != ScalaSerializer::DeserializationResult::OK)
                {
                    errorLevel = HajuErrorVisualizer::ErrorLevel::warning;
                }
                else
                {
                    errorLevel = HajuErrorVisualizer::ErrorLevel::noError;
                }

                switch (deserializationResult)
                {
                case ScalaSerializer::DeserializationResult::InvalidScalaFile:
                    displayMessage(
                        "The file " + currentFile.getFullPathName() + " is not a valid SCALA file.",
                        errorLevel);
                    break;

                case ScalaSerializer::DeserializationResult::NonAscendingPeriodInterval:
                    displayMessage(
                        "Scale with empty or descending period interval.",
                        errorLevel);
                    break;

                case ScalaSerializer::DeserializationResult::SizeSpecifiedAsZero:
                    displayMessage(
                        "Scale with size 0 specified.",
                        errorLevel);
                    break;

                case ScalaSerializer::DeserializationResult::NoTunigValuesFound:
                    displayMessage(
                        "No tuning values found.",
                        errorLevel);
                    break;

                case ScalaSerializer::DeserializationResult::LessTuningValuesThanSize:
                    displayMessage(
                        "Less tuning values specified than specified size.",
                        errorLevel);
                    break;

                case ScalaSerializer::DeserializationResult::MoreTuningValuesThanSize:
                    displayMessage(
                        "More tuning values specified than specified size.",
                        errorLevel);
                    break;

                 default:
                   displayMessage(
                        currentFile.getFullPathName() + " opened successfully.",
                        errorLevel);
                    break;
                 };

                 if (errorLevel != HajuErrorVisualizer::ErrorLevel::error)
                 {
                    theInstrument.tuningTable = newTuningTable;
                    sendChangeMessage();
                    repaint();
                 }
             }
        });
}

void TukarylSoundEdit::displayMessage(String message, HajuErrorVisualizer::ErrorLevel errorLevel)
{
    labelMessageArea->setText(message, juce::NotificationType::dontSendNotification);

    errorVisualizer.setErrorLevel(*labelMessageArea.get(), errorLevel, message);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TukarylSoundEdit" componentName=""
                 parentClasses="public juce::Component, public OscSubComponent::Listener, public juce::ChangeBroadcaster"
                 constructorParams="TukarylInstrument&amp; injectedInstrument"
                 variableInitialisers="theInstrument(injectedInstrument), errorVisualizer(getLookAndFeel())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="608" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="groupOscillators" id="b9219965a445713c" memberName="groupOscillators"
                  virtualName="" explicitFocusOrder="0" pos="8 32 97.765% 263"
                  title="Oscillators" textpos="36"/>
  <GENERICCOMPONENT name="osc1" id="5752b2c7ddf48ad8" memberName="osc1" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="16 88 62 200" class="OscSubComponent"
                    params="theInstrument.baseFrequency, theInstrument.baseOscLevel, false"/>
  <GENERICCOMPONENT name="osc2" id="8b807cc720421151" memberName="osc2" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="88 88 62 200" class="OscSubComponent"
                    params="theInstrument.partial1Frequency, theInstrument.partial1Level, true"/>
  <LABEL name="lblTuningDescription" id="2fa3694df70d7ee4" memberName="lblTuningDescription"
         virtualName="" explicitFocusOrder="0" pos="8 0 200 24" posRelativeW="3d4c2ccc04f7e5d2"
         edTextCol="ff000000" edBkgCol="0" labelText="Tuning description"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="12.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <TEXTBUTTON name="btnLoadScalaFile" id="3d4c2ccc04f7e5d2" memberName="btnLoadScalaFile"
              virtualName="" explicitFocusOrder="0" pos="240 0 150 24" buttonText="Scala file"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="btnTuningReset" id="b50a1895561623fe" memberName="btnTuningReset"
              virtualName="" explicitFocusOrder="0" pos="400 0 150 24" buttonText="Reset tuning"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="labelMessageArea" id="7851234199cd91c" memberName="labelMessageArea"
         virtualName="" explicitFocusOrder="0" pos="0 16R 100% 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Message area&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="groupMainEnvelope" id="2207b5aab078b03e" memberName="groupMainEnvelope"
                  virtualName="" explicitFocusOrder="0" pos="8 304 288 190" title="Main output envelope"/>
  <GENERICCOMPONENT name="mainEnvelopeComponent" id="dd5a17cc34537eab" memberName="mainEnvelopeComponent"
                    virtualName="" explicitFocusOrder="0" pos="24 320 254 160" class="EnvelopeEdit"
                    params="theInstrument.mainEnvelope.attack, theInstrument.mainEnvelope.decay, theInstrument.mainEnvelope.sustain, theInstrument.mainEnvelope.release"/>
  <GENERICCOMPONENT name="osc3" id="961fa27822f595c3" memberName="osc3" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="160 88 62 200" class="OscSubComponent"
                    params="theInstrument.partial2Frequency, theInstrument.partial2Level, true"/>
  <GENERICCOMPONENT name="osc4" id="5adac0e78771dc3a" memberName="osc4" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="232 88 62 200" class="OscSubComponent"
                    params="theInstrument.partial3Frequency, theInstrument.partial3Level, true"/>
  <GENERICCOMPONENT name="osc5" id="41d7ecd49034da33" memberName="osc5" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="304 88 62 200" class="OscSubComponent"
                    params="theInstrument.partial4Frequency, theInstrument.partial4Level, true"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

