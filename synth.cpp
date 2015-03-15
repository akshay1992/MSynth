#include "synth.h"
#include "math.h"

synth::WavetableSynth::WavetableSynth()
{
    current_phase = 0;
    tbl = NULL;
}

// TODO: freqMod and setFreq inline. Or any other speed optimization.
void synth::WavetableSynth::setFreq(float freq)
{
    frequency = freq;
    phase_inc = floor( frequency * (double) Tables::length() / SystemSR );

    //     //Frequency division (for control rate)
//    phase_inc = floor( frequency * (double) Tables::length() / ( SystemSR >> ( (LFState & 0x1) | LF_FREQ_DIV)) );
}

sample synth::WavetableSynth::freqMod(float freq)
{
    setFreq( (frequency + freq) * 0.5);
    return this->tick();
}

inline sample synth::WavetableSynth::tick()
{
    /*
     * Basic tick function template. Use this for simple traversal within the wavetable.
     * It is a virtual function and can be overridden based on specific requirements of
     * the derived class.
     */

    sample outValue = *(tbl + current_phase);
    current_phase += phase_inc;
    current_phase = current_phase & Tables::phase_mask();
    return outValue;
}



