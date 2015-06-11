#ifndef CONTROL
#define CONTROL

#include "audio_config.h"

namespace control {

class StagedEnvelope
{
public:
    sample out;                 // Current output sample
    control8 num_stages;
    sample8 current_stage;
    control16 * stage_times;
    control16 stage_ticker;
    sample8 retrigger;

    StagedEnvelope(void);
    control16 time_to_numSamples(float time);

    virtual void calculate_output(void) {out=0;}
    virtual void trigger(void) {current_stage++;}
    sample tick();

    void retrigger_on();
    void retrigger_off();

    sample operator()(void);
};

}

#endif
