#include "table.h"
#include "inttypes.h"
#include <math.h>
#include <stdlib.h>

double * gen::sine(int len)
{
    double *SineTable = (double* ) malloc(sizeof(double) * len);
    for (int i=0; i<len; i++)
    {
        *(SineTable+i) = sin(2*M_PI*i/len);
    }
    return SineTable;
}

double * gen::tri(int len)
{
    double *TriTable = (double* ) malloc(sizeof(double) * len);
    for (int i=0; i<len; i++)
    {
        *TriTable = sin(2*M_PI*i/len);
    }
    return TriTable;
}

double * gen::saw(int len)
{
    double *SawTable = (double* ) malloc(sizeof(double) * len);
    for (int i=0; i<len; i++)
    {
            *(SawTable+i) += sin(2*M_PI * i / len);
    }
    return SawTable;
}

double * gen::square(int len)
{
    double *SquareTable = (double* ) malloc(sizeof(double) * len);
    for (int i=0; i<len; i++)
    {
        *SquareTable = sin(2*M_PI*i/len);
    }
    return SquareTable;
}

//*****************************************************

int Tables::table_length(void)
{
    static int table_length = DEFAULT_TABLE_LENGTH;
    return table_length;
}

int Tables::phase_mask(void)
{
    static int table_length = DEFAULT_PHASE_MASK;
    return table_length;
}

double * Tables::sine()
{
    static double* tbl_sine;

    if (tbl_sine == NULL)
       {
           tbl_sine = gen::sine( Tables::table_length() );
       }
       return tbl_sine;
}

double * Tables::tri()
{
    static double* tbl_tri;

    if (tbl_tri == NULL)
       {
           tbl_tri = gen::tri(Tables::table_length());
       }
       return tbl_tri;
}

double * Tables::saw()
{
    static double* tbl_saw;

    if (tbl_saw == NULL)
       {
           tbl_saw = gen::saw(Tables::table_length());
       }
       return tbl_saw;
}

double * Tables::square()
{
    static double* tbl_square;

    if (tbl_square == NULL)
       {
           tbl_square = gen::square(Tables::table_length());
       }
       return tbl_square;
}
