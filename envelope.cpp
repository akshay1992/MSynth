#include <stdlib.h>
#include "envelope.h"
#include "math.h"

control::AttackDecay::AttackDecay(float attack_time, float decay_time)
{
    num_stages = 2;
    stage_times = (control16 *) calloc(num_stages, sizeof(control16));
    stage_times[0] = time_to_numSamples(attack_time);
    stage_times[1] = time_to_numSamples(decay_time);

    level_tick_times = (control16 *) calloc(num_stages, sizeof(control16));
    level_tick_times[0] = round( (float) stage_times[0]/127 );
    level_tick_times[1] = round( (float) stage_times[1]/127 );

    level_ticker = level_tick_times[0];
}

void control::AttackDecay::calculate_output(void)
{
    level_ticker--;
    if (level_ticker != 0)
        return;

    if (current_stage==ATTACK)
    {
        if(level_ticker == 0)
        {
            out.value = out.value+1;
            level_ticker = level_tick_times[current_stage];
        }
    }

    else if (current_stage == DECAY)
    {
        if(level_ticker == 0)
        {
            out.value = out.value-1;
            level_ticker = level_tick_times[current_stage];
        }
    }
}

void control::AttackDecay::trigger(void)
{
    current_stage = 0;
    out = 0;
    stage_ticker = 0;
    level_ticker = 0;
}
