#ifndef TABLE
#define TABLE

#include <stdlib.h>
#include "audio_config.h"

#define DEFAULT_TABLE_LENGTH 1024
#define DEFAULT_PHASE_MASK DEFAULT_TABLE_LENGTH-1

#define TABLE_DC 0
#define TABLE_PEAK 127


namespace gen {
    // Table filling functions
    sampleData *sine(int len);
    sampleData *tri(int len);
    sampleData *saw(int len);
    sampleData *square(int len);
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

    sampleData * sine();
    sampleData * tri();
    sampleData * saw();
    sampleData * square();

}


#endif //TABLE
