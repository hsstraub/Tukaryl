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
//[/Headers]

#include "EnvelopeEdit.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EnvelopeEdit::EnvelopeEdit (float& injectedAttackVariable, float& injectedDecayVariable, float& injectedSustainVariable, float& injectedReleaseVariable)
    : attackVariable(injectedAttackVariable), decayVariable(injectedDecayVariable), sustainVariable(injectedSustainVariable), releaseVariable(injectedReleaseVariable)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    sliderAttack.reset (new juce::Slider ("sliderAttack"));
    addAndMakeVisible (sliderAttack.get());
    sliderAttack->setRange (0, 2, 0.01);
    sliderAttack->setSliderStyle (juce::Slider::LinearVertical);
    sliderAttack->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    sliderAttack->addListener (this);

    sliderAttack->setBounds (16, 0, 30, 128);

    labelAttack.reset (new juce::Label ("labelAttack",
                                        TRANS ("Attack")));
    addAndMakeVisible (labelAttack.get());
    labelAttack->setFont (juce::Font (15.00f, juce::Font::plain));
    labelAttack->setJustificationType (juce::Justification::centredTop);
    labelAttack->setEditable (false, false, false);
    labelAttack->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelAttack->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelAttack->setBounds (0, 136, 62, 24);

    sliderRelease.reset (new juce::Slider ("sliderRelease"));
    addAndMakeVisible (sliderRelease.get());
    sliderRelease->setRange (0, 2, 0.01);
    sliderRelease->setSliderStyle (juce::Slider::LinearVertical);
    sliderRelease->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    sliderRelease->addListener (this);

    sliderRelease->setBounds (208, 0, 30, 128);

    labelRelease.reset (new juce::Label ("labelRelease",
                                         TRANS ("Release")));
    addAndMakeVisible (labelRelease.get());
    labelRelease->setFont (juce::Font (15.00f, juce::Font::plain));
    labelRelease->setJustificationType (juce::Justification::centredTop);
    labelRelease->setEditable (false, false, false);
    labelRelease->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelRelease->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelRelease->setBounds (192, 136, 62, 24);

    sliderDecay.reset (new juce::Slider ("sliderDecay"));
    addAndMakeVisible (sliderDecay.get());
    sliderDecay->setRange (0, 2, 0.01);
    sliderDecay->setSliderStyle (juce::Slider::LinearVertical);
    sliderDecay->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    sliderDecay->addListener (this);

    sliderDecay->setBounds (80, 0, 30, 128);

    labelDecay.reset (new juce::Label ("labelDecay",
                                       TRANS ("Decay")));
    addAndMakeVisible (labelDecay.get());
    labelDecay->setFont (juce::Font (15.00f, juce::Font::plain));
    labelDecay->setJustificationType (juce::Justification::centredTop);
    labelDecay->setEditable (false, false, false);
    labelDecay->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelDecay->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelDecay->setBounds (64, 136, 62, 24);

    sliderSustain.reset (new juce::Slider ("sliderSustain"));
    addAndMakeVisible (sliderSustain.get());
    sliderSustain->setRange (0, 1, 0.01);
    sliderSustain->setSliderStyle (juce::Slider::LinearVertical);
    sliderSustain->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    sliderSustain->addListener (this);

    sliderSustain->setBounds (144, 0, 30, 128);

    labelSustain.reset (new juce::Label ("labelSustain",
                                         TRANS ("Sustain")));
    addAndMakeVisible (labelSustain.get());
    labelSustain->setFont (juce::Font (15.00f, juce::Font::plain));
    labelSustain->setJustificationType (juce::Justification::centredTop);
    labelSustain->setEditable (false, false, false);
    labelSustain->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelSustain->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelSustain->setBounds (128, 136, 62, 24);


    //[UserPreSize]
    sliderAttack->setValue(attackVariable);
    sliderDecay->setValue(decayVariable);
    sliderSustain->setValue(sustainVariable);
    sliderRelease->setValue(releaseVariable);
    //[/UserPreSize]

    setSize (256, 160);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EnvelopeEdit::~EnvelopeEdit()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sliderAttack = nullptr;
    labelAttack = nullptr;
    sliderRelease = nullptr;
    labelRelease = nullptr;
    sliderDecay = nullptr;
    labelDecay = nullptr;
    sliderSustain = nullptr;
    labelSustain = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EnvelopeEdit::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EnvelopeEdit::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EnvelopeEdit::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderAttack.get())
    {
        //[UserSliderCode_sliderAttack] -- add your slider handling code here..
        attackVariable = sliderAttack->getValue();
        sendChangeMessage();
        //[/UserSliderCode_sliderAttack]
    }
    else if (sliderThatWasMoved == sliderRelease.get())
    {
        //[UserSliderCode_sliderRelease] -- add your slider handling code here..
        releaseVariable = sliderRelease->getValue();
        sendChangeMessage();
        //[/UserSliderCode_sliderRelease]
    }
    else if (sliderThatWasMoved == sliderDecay.get())
    {
        //[UserSliderCode_sliderDecay] -- add your slider handling code here..
        decayVariable = sliderDecay->getValue();
        sendChangeMessage();
        //[/UserSliderCode_sliderDecay]
    }
    else if (sliderThatWasMoved == sliderSustain.get())
    {
        //[UserSliderCode_sliderSustain] -- add your slider handling code here..
        sustainVariable = sliderSustain->getValue();
        sendChangeMessage();
        //[/UserSliderCode_sliderSustain]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EnvelopeEdit" componentName=""
                 parentClasses="public juce::Component, public juce::ChangeBroadcaster"
                 constructorParams="float&amp; injectedAttackVariable, float&amp; injectedDecayVariable, float&amp; injectedSustainVariable, float&amp; injectedReleaseVariable"
                 variableInitialisers="attackVariable(injectedAttackVariable), decayVariable(injectedDecayVariable), sustainVariable(injectedSustainVariable), releaseVariable(injectedReleaseVariable)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="256" initialHeight="160">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="sliderAttack" id="a347fb19da583b72" memberName="sliderAttack"
          virtualName="" explicitFocusOrder="0" pos="16 0 30 128" min="0.0"
          max="2.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelAttack" id="d3b401035144e02f" memberName="labelAttack"
         virtualName="" explicitFocusOrder="0" pos="0 136 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="sliderRelease" id="9ff57e166e767502" memberName="sliderRelease"
          virtualName="" explicitFocusOrder="0" pos="208 0 30 128" min="0.0"
          max="2.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelRelease" id="72d6f2a0484a707c" memberName="labelRelease"
         virtualName="" explicitFocusOrder="0" pos="192 136 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="sliderDecay" id="92ef75266e7af86" memberName="sliderDecay"
          virtualName="" explicitFocusOrder="0" pos="80 0 30 128" min="0.0"
          max="2.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelDecay" id="5e0ccbcb5d648017" memberName="labelDecay"
         virtualName="" explicitFocusOrder="0" pos="64 136 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <SLIDER name="sliderSustain" id="9b23709c8504fc47" memberName="sliderSustain"
          virtualName="" explicitFocusOrder="0" pos="144 0 30 128" min="0.0"
          max="1.0" int="0.01" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="labelSustain" id="e71a0400c01b2884" memberName="labelSustain"
         virtualName="" explicitFocusOrder="0" pos="128 136 62 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

