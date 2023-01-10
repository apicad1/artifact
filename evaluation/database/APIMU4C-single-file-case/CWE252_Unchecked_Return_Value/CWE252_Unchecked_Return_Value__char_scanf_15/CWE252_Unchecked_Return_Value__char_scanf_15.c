/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__char_scanf_15.c
Label Definition File: CWE252_Unchecked_Return_Value.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: scanf
 *    GoodSink: Check if scanf() fails
 *    BadSink : Do not check if scanf() fails
 * Flow Variant: 15 Control flow: switch(6)
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


void printLine (const char * line){}	// print line
int globalReturnsTrue() { return 1;}

int globalReturnsFalse() { return 0;}

int globalReturnsTrueOrFalse() { return (rand() % 2);}

#ifndef _WIN32
#include <wchar.h>
#endif

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__char_scanf_15_bad()
{
    switch(6)
    {
    case 6:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        /* FLAW: Do not check the return value */
        scanf("%99s\0", data);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        /* FIX: check the return value */
        if (scanf("%99s\0", data) == EOF)
        {
            printLine("scanf failed!");
        }
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        /* By initializing dataBuffer, we ensure this will not be the
         * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() and other variants */
        char dataBuffer[100] = "";
        char * data = dataBuffer;
        /* FIX: check the return value */
        if (scanf("%99s\0", data) == EOF)
        {
            printLine("scanf failed!");
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE252_Unchecked_Return_Value__char_scanf_15_good()
{
    good1();
    good2();
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
    CWE252_Unchecked_Return_Value__char_scanf_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__char_scanf_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
