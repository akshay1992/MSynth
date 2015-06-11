#include "control.h"

control::StagedEnvelope::StagedEnvelope()
{
    stage_ticker=0;
    current_stage=-1;
    retrigger = 1;
    out = 0;
}

control16 control::StagedEnvelope::time_to_numSamples(float time)
{
    return (control16) ( (float) SystemSR*time );
}

sample control::StagedEnvelope::tick()
{
    if (current_stage==-1)
        return out;

    if (stage_ticker>=stage_times[current_stage])
    {
        current_stage++;
        if(current_stage>num_stages-1)
            if(retrigger==0)
            {
                current_stage=-1;
                out = 0;
            }
            else
            {
                current_stage=0;
            }
        stage_ticker = 0;//stage_times[current_stage];
    }

    calculate_output();
    stage_ticker++;
    return out;
}

sample control::StagedEnvelope::operator()(void)
{
    return tick();
}

void control::StagedEnvelope::retrigger_on(void)
{
    retrigger = 1;
}

void control::StagedEnvelope::retrigger_off(void)
{
    retrigger = 0;
}
