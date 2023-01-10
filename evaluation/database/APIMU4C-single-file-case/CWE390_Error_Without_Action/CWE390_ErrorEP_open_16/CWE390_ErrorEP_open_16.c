/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fopen_16.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fopen
 *    GoodSink: Check to see if fopen() failed and handle errors properly
 *    BadSink : Check to see if fopen() failed, but fail to handle errors
 * Flow Variant: 16 Control flow: while(1)
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

int CWE390_Error_Without_Action__fopen_16_bad()
{
    while(1)
    {
        {
            FILE * fileDesc = NULL;
            fileDesc = fopen("file.txt", "w+");
            /* FLAW: Check to see if fopen failed, but do nothing about it */
            if (fileDesc == NULL)
            {
                return true;
            }
            fclose(fileDesc);return true;
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the while loop */
static int good1()
{
    while(1)
    {
        {
            FILE * fileDesc = NULL;
            fileDesc = fopen("file.txt", "w+");
            /* FIX: Check to see if fopen failed and handle the error */
            if (fileDesc == NULL)
            {
                printLine("fopen() failed");
                return false;
            }
            fclose(fileDesc);return true;
        }
        break;
    }
}

int CWE390_Error_Without_Action__fopen_16_good()
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
    CWE390_Error_Without_Action__fopen_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__fopen_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif