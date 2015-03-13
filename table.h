#ifndef TABLE
#define TABLE

#include "inttypes.h"
#include <cstdlib>

#define DEFAULT_TABLE_LENGTH 1023
#define DEFAULT_PHASE_MASK DEFAULT_TABLE_LENGTH

// Global Sample Rate
#define SystemSR 44100

namespace gen {
    // Table filling functions
    double *sine(int len);
    double *tri(int len);
    double *saw(int len);
    double *square(int len);
}

namespace Tables{

    // Table containers
    //  These funcitons return singletons of a table
    int table_length(void);
    int phase_mask(void);
    double * sine();
    double * tri();
    double * saw();
    double * square();

}


#endif //TABLE
