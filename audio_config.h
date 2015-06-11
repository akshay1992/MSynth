#ifndef AUDIO_CONFIG
#define AUDIO_CONFIG

#include "inttypes.h"

// TODO: Frequency division of sample rate (for control rate) - Comments in synth and ugens.
#define LF_FREQ_DIV 2

#define SystemSR 16000

typedef int8_t sample8 ; // Default signed 8-bit audio
typedef uint8_t control8;   // For 8-bit unsigned operations
typedef uint16_t control16; // For 16-bit unsigned operations

class sample
{
    /*
     * An alias for sampleData that takes care of all operations
     */
public:
    sample8 value;
    sample(void){value=0;}
    sample(char val)
    {
        value = val;
    }

    sample operator=(char val)
    {
        return value = val;
    }

    sample operator+(sample s)
    {
        int result = s.value+value;
        result = result/2;
        return sample(result);
    }

    sample operator-()
    {
        value = -value;
        return *this;
    }

    sample operator-(sample s)
    {
        if ((this->value*s.value)>=0)
            return sample(value - s.value);
        else
            return sample((value - s.value) / 2);
    }

    sample operator*(sample s)
    {
        int number = (s.value*value);
        number /= 128;
        if (number==128)    // Accounts for -128*-128
            return sample(127);
        else
            return sample(number);
    }
};

#endif
