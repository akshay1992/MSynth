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
    sample8 *sine(int len);
    sample8 *tri(int len);
    sample8 *saw(int len);
    sample8 *square(int len);
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

    sample8 * sine();
    sample8 * tri();
    sample8 * saw();
    sample8 * square();

}


#endif //TABLE
