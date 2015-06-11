#ifndef AUDIO_CONFIG
#define AUDIO_CONFIG

// TODO: Frequency division of sample rate (for control rate) - Comments in synth and ugens.
#define LF_FREQ_DIV 2

#define SystemSR 16000

typedef char sampleData ;

class sample
{
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
        return sample((char)result);
    }

    sample operator*(sample s)
    {
        int number = (s.value*value);
        number /= 256;
        return sample((char)number);
    }
};

// Old:
//typedef char sample;    // Signed 8-bit Audio Sample
//typedef int sample16;   // Signed 16-bit audio (used behind the scenes for + and * operations)

#endif
