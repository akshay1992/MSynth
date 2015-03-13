#include "table.h"
#include <math.h>
#include <stdlib.h>

sample * gen::sine(int len)
{
    sample *SineTable = (sample* ) malloc(sizeof(sample) * len);
    for (int i=0; i<len; i++)
    {
        *(SineTable+i) = 128 + 127 * sin(2*M_PI*i/len);
    }
    return SineTable;
}

sample * gen::tri(int len)
{
    sample *TriTable = (sample* ) malloc(sizeof(sample) * len);
    for (int i=0 ; i<=len/4; i++)
    {
        TriTable[i] = 128 + 127*4.0/len * i;
    }
    for (int i=1; i<=len/2; i++)
    {
        TriTable[i + len/4] = 255 - 255*2.0/len * i;
    }
    for (int i=1; i<=len/4; i++)
    {
        TriTable[i + 3*len/4] = 127*4.0/len * i;
    }

    return TriTable;
}

sample * gen::saw(int len)
{
    /* Square doesn't *really* have a wavetable. It simple does a comparison between
     * the current phase and 0.5*table_length and returns either a 1 or 0.
     *
     * To avoid an extra division step, 0.5*table_length is stored in the table.
     */
    sample *SawTable = (sample* ) malloc(sizeof(sample));
    *SawTable = len/2.0;
    return SawTable;
}

sample * gen::square(int len)
{
    // NOT USED
    sample *SquareTable = (sample* ) malloc(sizeof(sample) * len);
    for (int i=0; i<len/2.0; i++)
    {
        *SquareTable = sin(2*M_PI*i/len);
    }
    return SquareTable;
}

//*****************************************************

int Tables::length(void)
{
    static int table_length = DEFAULT_TABLE_LENGTH;
    return table_length;
}

int Tables::phase_mask(void)
{
    static int table_length = DEFAULT_PHASE_MASK;
    return table_length;
}

sample * Tables::sine()
{
    static sample* tbl_sine;

    if (tbl_sine == NULL)
       {
           tbl_sine = gen::sine( Tables::length() );
       }
       return tbl_sine;
}

sample * Tables::tri()
{
    static sample* tbl_tri;

    if (tbl_tri == NULL)
       {
           tbl_tri = gen::tri(Tables::length());
       }
       return tbl_tri;
}

sample * Tables::saw()
{
    static sample* tbl_saw;

    if (tbl_saw == NULL)
       {
           tbl_saw = gen::saw(Tables::length());
       }
       return tbl_saw;
}

sample * Tables::square()
{
    static sample* tbl_square;

    if (tbl_square == NULL)
       {
           tbl_square = gen::square(Tables::length());
       }
       return tbl_square;
}
