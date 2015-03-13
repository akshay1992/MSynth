#include "synth.h"
#include "math.h"

synth::WavetableSynth::WavetableSynth()
{
    current_phase = 0;
    tbl = NULL;
}

sample synth::WavetableSynth::freqMod(float freq)
{
    phase_inc = floor( frequency * (double) Tables::length() / SystemSR );
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

void synth::WavetableSynth::setFreq(float freq)
{
    frequency = freq;
    phase_inc = lrint( frequency * (double) Tables::length() / SystemSR );
}


