#ifndef SYNTH
#define SYNTH

#include "table.h"


namespace synth{

//const float MIN_WAVETABLE_FREQ = SystemSR/Tables::length();

class WavetableSynth
    {
    public:
        float frequency;
        float phase;
        int current_phase;
        int phase_inc;
        sample *tbl;

        WavetableSynth();
        void setFreq(float freq);
        sample freqMod(float freq);
        virtual sample tick();

protected:
    };

}   // End of synth namespace

#endif // SYNTH
