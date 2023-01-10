/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fgets_char_10.c
Label Definition File: CWE390_Error_Without_Action__fgets.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks:
 *    GoodSink: Check if fgets() failed and handle errors properly
 *    BadSink : Check to see if fgets() failed, but do nothing about it
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
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

#ifndef OMITBAD

void CWE390_Error_Without_Action__fgets_char_10_bad()
{
    if(globalTrue)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            printLine("Please enter a string: ");
            /* FLAW: check the return value, but do nothing if there is an error */
            if (fgets(data, 100, stdin) == NULL)
            {
                /* do nothing */
            }
            printLine(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            printLine("Please enter a string: ");
            /* FIX: check the return value and handle errors properly */
            if (fgets(data, 100, stdin) == NULL)
            {
                printLine("fgets failed!");
                exit(1);
            }
            printLine(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        {
            /* By initializing dataBuffer, we ensure this will not be the
             * CWE 690 (Unchecked Return Value To NULL Pointer) flaw for fgets() */
            char dataBuffer[100] = "";
            char * data = dataBuffer;
            printLine("Please enter a string: ");
            /* FIX: check the return value and handle errors properly */
            if (fgets(data, 100, stdin) == NULL)
            {
                printLine("fgets failed!");
                exit(1);
            }
            printLine(data);
        }
    }
}

void CWE390_Error_Without_Action__fgets_char_10_good()
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
    CWE390_Error_Without_Action__fgets_char_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__fgets_char_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
