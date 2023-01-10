/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__fopen_11.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fopen
 *    GoodSink: Check to see if fopen() failed and handle errors properly
 *    BadSink : Check to see if fopen() failed, but fail to handle errors
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
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

void CWE390_Error_Without_Action__fopen_11_bad()
{
    if(globalReturnsTrue())
    {
        {
            FILE * fileDesc = NULL;
            fileDesc = fopen("file.txt", "w+");
            /* FLAW: Check to see if fopen failed, but do nothing about it */
            if (fileDesc == NULL)
            {
                /* do nothing */
            }
            fclose(fileDesc);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(globalReturnsFalse()) instead of if(globalReturnsTrue()) */
static void good1()
{
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            FILE * fileDesc = NULL;
            fileDesc = fopen("file.txt", "w+");
            /* FIX: Check to see if fopen failed and handle the error */
            if (fileDesc == NULL)
            {
                printLine("fopen() failed");
                exit(1);
            }
            fclose(fileDesc);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalReturnsTrue())
    {
        {
            FILE * fileDesc = NULL;
            fileDesc = fopen("file.txt", "w+");
            /* FIX: Check to see if fopen failed and handle the error */
            if (fileDesc == NULL)
            {
                printLine("fopen() failed");
                exit(1);
            }
            fclose(fileDesc);
        }
    }
}

void CWE390_Error_Without_Action__fopen_11_good()
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
    CWE390_Error_Without_Action__fopen_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__fopen_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
