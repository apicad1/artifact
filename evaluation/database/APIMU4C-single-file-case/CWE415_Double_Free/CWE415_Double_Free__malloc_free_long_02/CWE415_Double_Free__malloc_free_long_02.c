/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_02.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define ALLOCA alloca
#define true 1
#define false 0

/* The variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their 
   initialized values. */
const int GLOBAL_CONST_TRUE = 1; /* true */
const int GLOBAL_CONST_FALSE = 0; /* false */
const int GLOBAL_CONST_FIVE = 5; 

/* The variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
int globalTrue = 1; /* true */
int globalFalse = 0; /* false */
int globalFive = 5; 


/* struct used in some test cases as a custom type */
typedef struct _twoIntsStruct
{
    int intOne;
    int intTwo;
} twoIntsStruct;
void printLine(const char * line);
void printIntLine (int intNumber);
void printLongLongLine(int64_t longLongIntNumber);
void printStructLine(const twoIntsStruct * structTwoIntsStruct);
int globalReturnsTrue() { return 1;}

int globalReturnsFalse() { return 0;}

int globalReturnsTrueOrFalse() { return (rand() % 2);}

#include <wchar.h>

#ifndef OMITBAD

void CWE415_Double_Free__malloc_free_long_02_bad()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
        free(data);
    }
    if(1)
    {
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 1 to 0 */
static void goodB2G1()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
        free(data);
    }
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* do nothing */
        /* FIX: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
        free(data);
    }
    if(1)
    {
        /* do nothing */
        /* FIX: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 1 to 0 */
static void goodG2B1()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        data = (long *)malloc(100*sizeof(long));
        /* FIX: Do NOT free data in the source - the bad sink frees data */
    }
    if(1)
    {
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        /* FIX: Do NOT free data in the source - the bad sink frees data */
    }
    if(1)
    {
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

void CWE415_Double_Free__malloc_free_long_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE415_Double_Free__malloc_free_long_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_long_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
