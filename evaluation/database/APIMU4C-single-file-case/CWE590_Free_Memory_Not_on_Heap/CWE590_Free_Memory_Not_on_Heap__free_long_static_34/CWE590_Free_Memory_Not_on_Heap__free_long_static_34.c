/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Memory_Not_on_Heap__free_long_static_34.c
Label Definition File: CWE590_Free_Memory_Not_on_Heap__free.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free Memory Not on Heap
 * BadSource: static Data buffer is declared static on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
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
void printLongLine(long longNumber);
void printLongLongLine(int64_t longLongIntNumber);
void printStructLine(const twoIntsStruct * structTwoIntsStruct);
int globalReturnsTrue() { return 1;}

int globalReturnsFalse() { return 0;}

int globalReturnsTrueOrFalse() { return (rand() % 2);}

#include <wchar.h>

typedef union
{
    long * unionFirst;
    long * unionSecond;
} CWE590_Free_Memory_Not_on_Heap__free_long_static_34_unionType;

#ifndef OMITBAD

void CWE590_Free_Memory_Not_on_Heap__free_long_static_34_bad()
{
    long * data;
    CWE590_Free_Memory_Not_on_Heap__free_long_static_34_unionType myUnion;
    data = NULL; /* Initialize data */
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        static long dataBuffer[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5L;
            }
        }
        data = dataBuffer;
    }
    myUnion.unionFirst = data;
    {
        long * data = myUnion.unionSecond;
        printLongLine(data[0]);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    long * data;
    CWE590_Free_Memory_Not_on_Heap__free_long_static_34_unionType myUnion;
    data = NULL; /* Initialize data */
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        long * dataBuffer = (long *)malloc(100*sizeof(long));
        if (dataBuffer == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5L;
            }
        }
        data = dataBuffer;
    }
    myUnion.unionFirst = data;
    {
        long * data = myUnion.unionSecond;
        printLongLine(data[0]);
        /* POTENTIAL FLAW: Possibly deallocating memory allocated on the stack */
        free(data);
    }
}

void CWE590_Free_Memory_Not_on_Heap__free_long_static_34_good()
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
    CWE590_Free_Memory_Not_on_Heap__free_long_static_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE590_Free_Memory_Not_on_Heap__free_long_static_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
