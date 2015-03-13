#ifndef SYNTH
#define SYNTH

#include <inttypes.h>
#include <cstdlib>
#include "table.h"
#include "math.h"

namespace synth{

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
        virtual inline sample tick();

protected:
    };

}   // End of synth namespace

#endif // SYNTH
