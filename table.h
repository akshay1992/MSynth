#ifndef TABLE
#define TABLE

#include <stdlib.h>

#define DEFAULT_TABLE_LENGTH 1024
#define DEFAULT_PHASE_MASK DEFAULT_TABLE_LENGTH-1

#define TABLE_DC 0
#define TABLE_PEAK 127

// TODO: Frequency division of sample rate (for control rate) - Comments in synth and ugens.
#define LF_FREQ_DIV 2

#define SystemSR 16000
typedef int8_t sample;

namespace gen {
    // Table filling functions
    sample *sine(int len);
    sample *tri(int len);
    sample *saw(int len);
    sample *square(int len);
}

namespace Tables{

    // These return table parameters. (inlined for optimization)

    inline int length(void)
    {
        static int table_length = DEFAULT_TABLE_LENGTH;
        return table_length;
    }

    inline int phase_mask(void)
    {
        static int phase_mask = DEFAULT_PHASE_MASK;
        return phase_mask;
    }

    // Table containers:
    // These funcitons return singletons of a table

    sample * sine();
    sample * tri();
    sample * saw();
    sample * square();

}


#endif //TABLE
