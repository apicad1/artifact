/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_17.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: alloca Data buffer is allocated on the stack with alloca()
 * GoodSource: Allocate memory on the heap
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 17 Control flow: for loops
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

void CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_17_bad()
{
    int i;
    int64_t * data;
    data = NULL; /* Initialize data */
    for(i = 0; i < 1; i++)
    {
        {
            /* FLAW: data is allocated on the stack and deallocated in the BadSink */
            int64_t * dataBuffer = (int64_t *)ALLOCA(100*sizeof(int64_t));
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5LL;
                }
            }
            data = dataBuffer;
        }
    }
    printLongLongLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the for statements */
static void goodG2B()
{
    int h;
    int64_t * data;
    data = NULL; /* Initialize data */
    for(h = 0; h < 1; h++)
    {
        {
            /* FIX: data is allocated on the heap and deallocated in the BadSink */
            int64_t * dataBuffer = (int64_t *)malloc(100*sizeof(int64_t));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5LL;
                }
            }
            data = dataBuffer;
        }
    }
    printLongLongLine(data[0]);
    /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
    free(data);
}

void CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_17_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
