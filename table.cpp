#include "table.h"
#include <math.h>
#include <stdlib.h>

sample * gen::sine(int len)
{
    sample *SineTable = (sample* ) malloc(sizeof(sample) * len);
    for (int i=0; i<len; i++)
    {
        *(SineTable+i) = TABLE_DC + TABLE_PEAK* sin(2*M_PI*i/len);
    }
    return SineTable;
}

sample * gen::tri(int len)
{
    sample *TriTable = (sample* ) malloc(sizeof(sample) * len);
    for (int i=0 ; i<=len/4; i++)
    {
        TriTable[i] = TABLE_DC + TABLE_PEAK*4.0/len * i;
    }
    for (int i=1; i<=len/2; i++)
    {
        TriTable[i + len/4] = (TABLE_DC+TABLE_PEAK) - (TABLE_PEAK)*4.0/len * i;
    }
    for (int i=1; i<=len/4; i++)
    {
        TriTable[i + 3*len/4] = TABLE_PEAK*4.0/len * i + (TABLE_DC-TABLE_PEAK);
    }

    return TriTable;
}

sample * gen::saw(int len)
{
    sample *SawTable = (sample* ) malloc(sizeof(sample) * len);
    for (int i=0; i<len; i++)
    {
        *(SawTable+i) = (2.0*TABLE_PEAK)/len * i + (TABLE_DC-TABLE_PEAK) ;
    }
    return SawTable;
}

sample * gen::square(int len)
{
    sample *SquareTable = (sample* ) malloc(sizeof(sample) * len);
    for(int i=0; i<=len/2; i++)
    {
        *(SquareTable+i) = TABLE_DC+TABLE_PEAK;
        *(SquareTable+i+len/2) = TABLE_DC-TABLE_PEAK;
    }
    return SquareTable;
}

//*****************************************************

//inline int Tables::length(void)
//{
//    static int table_length = DEFAULT_TABLE_LENGTH;
//    return table_length;
//}

//inline int Tables::phase_mask(void)
//{
//    static int phase_mask = DEFAULT_PHASE_MASK;
//    return phase_mask;
//}

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
