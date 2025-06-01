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
//[/Headers]

#include "TukarylSoundEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TukarylSoundEdit::TukarylSoundEdit (TukarylInstrument& injectedInstrument)
    : theInstrument(injectedInstrument)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    osc1.reset (new OscSubComponent (theInstrument.baseFrequency, theInstrument.baseOscLevel, false));
    addAndMakeVisible (osc1.get());
    osc1->setName ("osc1");

    osc1->setBounds (8, 24, 70, 224);

    osc2.reset (new OscSubComponent (theInstrument.partial1Frequency, theInstrument.partial1Level, true));
    addAndMakeVisible (osc2.get());
    osc2->setName ("osc2");

    osc2->setBounds (96, 24, 70, 224);

    osc2->addListener(this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TukarylSoundEdit::~TukarylSoundEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    osc1 = nullptr;
    osc2 = nullptr;


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

    osc1->setTopLeftPosition(getXPosOfFrequency(IntervalModel::perfectPrime()) - osc1->getWidth() / 2, OSCTOP);

    osc2->setTopLeftPosition(getXPosOfFrequency(theInstrument.partial1Frequency) - osc2->getWidth() / 2, OSCTOP);
    //[/UserPaint]
}

void TukarylSoundEdit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
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

    paintRulerMark(g, IntervalModel::perfectPrime());
    paintRulerMark(g, maxFrequency);

    for (auto freqIter = theInstrument.tuningTable.begin(); freqIter != theInstrument.tuningTable.end(); freqIter++)
    {
           paintRulerMark(g, *freqIter);
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

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TukarylSoundEdit" componentName=""
                 parentClasses="public juce::Component" constructorParams="TukarylInstrument&amp; injectedInstrument"
                 variableInitialisers="theInstrument(injectedInstrument)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="osc1" id="5752b2c7ddf48ad8" memberName="osc1" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="8 24 70 224" class="OscSubComponent"
                    params="&quot;Base&quot;, theInstrument.baseOscLevel"/>
  <GENERICCOMPONENT name="osc2" id="8b807cc720421151" memberName="osc2" virtualName="OscSubComponent"
                    explicitFocusOrder="0" pos="96 24 70 224" class="OscSubComponent"
                    params="&quot;Partial 1&quot;, theInstrument.partial1Level"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

