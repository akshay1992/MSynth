#ifndef TABLE
#define TABLE

//#include "inttypes.h"
#include <stdlib.h>

#define DEFAULT_TABLE_LENGTH 1024
#define DEFAULT_PHASE_MASK DEFAULT_TABLE_LENGTH-1

typedef unsigned int sample;

// Global Sample Rate
#define SystemSR 44100

namespace gen {
    // Table filling functions
    sample *sine(int len);
    sample *tri(int len);
    sample *saw(int len);
    sample *square(int len);
}

namespace Tables{

    // Table containers
    //  These funcitons return singletons of a table
    int length(void);
    int phase_mask(void);
    sample * sine();
    sample * tri();
    sample * saw();
    sample * square();

}


#endif //TABLE
