/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fprintf
 *    GoodSink: Correctly check if fprintf() failed
 *    BadSink : Incorrectly check if fprintf() failed
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
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

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: fprintf() might fail, in which case the return value will be negative, but
         * we are checking to see if the return value is 0 */
        if (fprintf(stdout, "%s\n", "string") == 0)
        {
            printLine("fprintf failed!");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check for the correct return value */
        if (fprintf(stdout, "%s\n", "string") < 0)
        {
            printLine("fprintf failed!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: check for the correct return value */
        if (fprintf(stdout, "%s\n", "string") < 0)
        {
            printLine("fprintf failed!");
        }
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__char_fprintf_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
