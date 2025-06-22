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

    osc1.reset (new OscSubComponent (theInstrument.baseFrequency, theInstrument.baseOscLevel, false));
    addAndMakeVisible (osc1.get());
    osc1->setName ("osc1");

    osc1->setBounds (8, 56, 70, 224);

    osc2.reset (new OscSubComponent (theInstrument.partial1Frequency, theInstrument.partial1Level, true));
    addAndMakeVisible (osc2.get());
    osc2->setName ("osc2");

    osc2->setBounds (96, 56, 70, 224);

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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    osc2->addListener(this);
    //[/Constructor]
}

TukarylSoundEdit::~TukarylSoundEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    osc1 = nullptr;
    osc2 = nullptr;
    lblTuningDescription = nullptr;
    btnLoadScalaFile = nullptr;
    btnTuningReset = nullptr;
    labelMessageArea = nullptr;


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

    osc1->setTopLeftPosition(getXPosOfFrequency(IntervalModel::perfectPrime()) - osc1->getWidth() / 2, OSCTOP);

    osc2->setTopLeftPosition(getXPosOfFrequency(theInstrument.partial1Frequency) - osc2->getWidth() / 2, OSCTOP);
    //[/UserPaint]
}

void TukarylSoundEdit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    // auto area = getLocalBounds();
    //[/UserPreResize]

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
        repaint();
        //[/UserButtonCode_btnTuningReset]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TukarylSoundEdit::addChangeListener (juce::ChangeListener* const listener)
{
    osc1->addChangeListener(listener);
    osc2->addChangeListener(listener);
}

void TukarylSoundEdit::OnDrag(OscSubComponent* component)
{
    if (component == osc2.get())
    {
        auto dragStart = getLocalPoint(this, component->getDragStart());
        auto dragEnd = getLocalPoint(this, component->getDragEnd());
        auto displacement = dragEnd.getX() - dragStart.getX();

        auto thisWidth = getWidth();
        auto oscWidth = osc2->getWidth();

        double newLeftPos = osc2->getX() + displacement;
        if (newLeftPos <= osc1->getRight())
        {
            newLeftPos = osc1->getRight() + 1;
        }
        else if (newLeftPos >= thisWidth - oscWidth)
        {
            newLeftPos = thisWidth - oscWidth - 1;
        }

        osc2->setFrequency(getFrequencyOfXPos(newLeftPos + oscWidth / 2));
        repaint();

    }
}

void TukarylSoundEdit::paintRuler(juce::Graphics& g)
{
    g.setColour(getLookAndFeel().findColour(juce::TextEditor::textColourId));
    g.drawLine(0, RULERYPOS, getRight(), RULERYPOS);

    auto baseInterval = IntervalModel::perfectPrime();

    while (baseInterval < maxFrequency)
    {
        paintRulerMark(g, baseInterval);

        for (auto freqIter = theInstrument.tuningTable.begin(); freqIter != theInstrument.tuningTable.end(); freqIter++)
        {
            auto currentInterval = baseInterval.add(*freqIter);
            if (currentInterval > maxFrequency)
            {
                break;
            }

            paintRulerMark(g, currentInterval);
        }

        baseInterval = baseInterval.add(theInstrument.tuningTable.periodInterval());
    }
}

void TukarylSoundEdit::paintRulerMark(juce::Graphics& g, IntervalModel frequency)
{
    auto xPos = getXPosOfFrequency(frequency);
    if (xPos >= 0 && xPos <= getWidth())
    {
        g.setColour(getLookAndFeel().findColour(juce::TextEditor::textColourId));
        g.setFont(RULERTEXTSIZE);

        auto oscWidth = osc2->getWidth();

        g.drawLine(xPos, RULERYPOS, xPos, RULERYPOS - RULERMARKHEIGHT);
        g.drawText(frequency.toString(), xPos - oscWidth/2, RULERYPOS - RULERMARKHEIGHT- RULERTEXTSIZE - 1, oscWidth, RULERTEXTSIZE, juce::Justification::centred);
    }
}

int TukarylSoundEdit::getXPosOfFrequency(IntervalModel frequency)
{
    return OSCHORIZMARGIN + (getWidth() - 2 * OSCHORIZMARGIN) * frequency.getValueInCents() / maxFrequency.getValueInCents();
}

IntervalModel TukarylSoundEdit::getFrequencyOfXPos(double xPos)
{
    return IntervalModel(
        maxFrequency.getValueInCents() * (xPos - OSCHORIZMARGIN) / (getWidth() - 2 * OSCHORIZMARGIN));
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
                 parentClasses="public juce::Component, public OscSubComponent::Listener"
                 constructorParams="TukarylInstrument&amp; injectedInstrument"
                 variableInitialisers="theInstrument(injectedInstrument), errorVisualizer(getLookAndFeel())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="osc1" id="5752b2c7ddf48ad8" memberName="osc1" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="8 56 70 224" class="OscSubComponent"
                    params="theInstrument.baseFrequency, theInstrument.baseOscLevel, false"/>
  <GENERICCOMPONENT name="osc2" id="8b807cc720421151" memberName="osc2" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="96 56 70 224" class="OscSubComponent"
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

