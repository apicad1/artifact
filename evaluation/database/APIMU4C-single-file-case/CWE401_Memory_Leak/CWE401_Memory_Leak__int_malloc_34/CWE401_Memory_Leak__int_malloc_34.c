/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__int_malloc_34.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
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

typedef union
{
    int * unionFirst;
    int * unionSecond;
} CWE401_Memory_Leak__int_malloc_34_unionType;

#ifndef OMITBAD

void CWE401_Memory_Leak__int_malloc_34_bad()
{
    int * data;
    CWE401_Memory_Leak__int_malloc_34_unionType myUnion;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (int *)malloc(100*sizeof(int));
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    CWE401_Memory_Leak__int_malloc_34_unionType myUnion;
    data = NULL;
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (int *)ALLOCA(100*sizeof(int));
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    CWE401_Memory_Leak__int_malloc_34_unionType myUnion;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (int *)malloc(100*sizeof(int));
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
        /* FIX: Deallocate memory */
        free(data);
    }
}

void CWE401_Memory_Leak__int_malloc_34_good()
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
    CWE401_Memory_Leak__int_malloc_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__int_malloc_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
