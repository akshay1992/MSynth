#ifndef ENVELOPE
#define ENVELOPE

#include "control.h"

namespace control
{

class AttackDecay : public control::StagedEnvelope
{
public:
    AttackDecay(float attack_time, float decay_time);

    typedef enum {
        OFF = -1,
        ATTACK = 0,
        DECAY = 1
    } stages;

    control8 level_ticker;
    control16 * level_tick_times;

    void calculate_output(void);
    void trigger(void);
};

}


#endif
