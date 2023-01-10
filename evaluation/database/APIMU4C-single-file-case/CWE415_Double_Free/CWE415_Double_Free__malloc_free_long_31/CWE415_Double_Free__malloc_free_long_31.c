/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_long_31.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-31.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 31 Data flow using a copy of data within the same function
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

void CWE415_Double_Free__malloc_free_long_31_bad()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    {
        long * dataCopy = data;
        long * data = dataCopy;
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    {
        long * dataCopy = data;
        long * data = dataCopy;
        /* POTENTIAL FLAW: Possibly freeing memory twice */
        free(data);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    long * data;
    /* Initialize data */
    data = NULL;
    data = (long *)malloc(100*sizeof(long));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    {
        long * dataCopy = data;
        long * data = dataCopy;
        /* do nothing */
        /* FIX: Don't attempt to free the memory */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE415_Double_Free__malloc_free_long_31_good()
{
    goodG2B();
    goodB2G();
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
    CWE415_Double_Free__malloc_free_long_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_long_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
