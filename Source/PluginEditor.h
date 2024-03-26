/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

// CUSTOM POTIKAT SLIDEREITTEN TILALLE, tehdään oma class johon viitataan,
// jottei tarvi kirjoittaa aina uudestaan
struct CustomRotatySlider : juce::Slider
{
    CustomRotatySlider() : juce::Slider(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag,
                                        juce::Slider::TextEntryBoxPosition::NoTextBox)
    {

    }
};

//==============================================================================
/**
*/
class EQ1AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    EQ1AudioProcessorEditor (EQ1AudioProcessor&);
    ~EQ1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    EQ1AudioProcessor& audioProcessor;

    // SLIDEREITTEN LISÄYS
    CustomRotatySlider peakFreqSlider,
        peakGainSlider,
        peakQualitySlider,
        lowCutFreqSlider,
        highCutFreqSlider,
        lowCutSlopeSlider,
        highCutSlopeSlider;

    // YHDISTÄMINEN PARAMETREIHIN
    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;

    Attachment peakFreqSliderAttachment,
                peakGainSliderAttachment,
                peakQualitySliderAttachment,
                lowCutFreqSliderAttachment,
                highCutFreqSliderAttachment,
                lowCutSlopeSliderAttachment,
                highCutSlopeSliderAttachment;
                
    
    std::vector<juce::Component*> getComps();

    MonoChain monoChain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQ1AudioProcessorEditor)
};
