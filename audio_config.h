#ifndef AUDIO_CONFIG
#define AUDIO_CONFIG

// TODO: Frequency division of sample rate (for control rate) - Comments in synth and ugens.
#define LF_FREQ_DIV 2

#define SystemSR 16000

typedef char sampleData ; // Default signed 8-bit audio

class sample
{
    /*
     * An alias for sampleData that takes care of all operations
     */
public:
    sampleData value;
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
