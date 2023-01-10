/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_12.c
Label Definition File: CWE401_Memory_Leak__malloc_realloc.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * Sinks:
 *    GoodSink: Ensure the memory block pointed to by data is always freed
 *    BadSink : malloc() and use then realloc() and use data before free()
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
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

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            /* FLAW: If realloc() fails, the initial memory block will not be freed() */
            data = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            if (data != NULL)
            {
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
                free(data);
            }
        }
    }
    else
    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            twoIntsStruct * tmpData;
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            tmpData = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
            * allocated with realloc() */
            if (tmpData != NULL)
            {
                data = tmpData;
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
            }
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            twoIntsStruct * tmpData;
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            tmpData = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
            * allocated with realloc() */
            if (tmpData != NULL)
            {
                data = tmpData;
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
            }
            free(data);
        }
    }
    else
    {
        {
            twoIntsStruct * data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
            twoIntsStruct * tmpData;
            /* Initialize and make use of data */
            data[0].intOne = 0;
            data[0].intTwo = 0;
            printStructLine(&data[0]);
            tmpData = (twoIntsStruct *)realloc(data, (130000)*sizeof(twoIntsStruct));
            /* FIX: Ensure realloc() was successful before assigning data to the memory block
            * allocated with realloc() */
            if (tmpData != NULL)
            {
                data = tmpData;
                /* Reinitialize and make use of data */
                data[0].intOne = 1;
                data[0].intTwo = 1;
                printStructLine(&data[0]);
            }
            free(data);
        }
    }
}

void CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_12_good()
{
    good1();
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
    CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE401_Memory_Leak__malloc_realloc_twoIntsStruct_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
