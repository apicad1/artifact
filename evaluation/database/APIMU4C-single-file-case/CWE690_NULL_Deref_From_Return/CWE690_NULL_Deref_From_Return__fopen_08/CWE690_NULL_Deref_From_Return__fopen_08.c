/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_08.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
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


void printLine(const char * line);
void printIntLine (int intNumber);
void printLongLine(long longNumber);
void printLongLongLine(int64_t longLongIntNumber);
int globalReturnsTrue() { return 1;}

int globalReturnsFalse() { return 0;}

int globalReturnsTrueOrFalse() { return (rand() % 2);}

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE690_NULL_Deref_From_Return__fopen_08_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    if(staticReturnsTrue())
    {
        /* FLAW: if the fopen failed, data will be NULL here */
        fclose(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing staticReturnsTrue() to staticReturnsFalse() */
static void goodB2G1()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
    if(staticReturnsTrue())
    {
        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE690_NULL_Deref_From_Return__fopen_08_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE690_NULL_Deref_From_Return__fopen_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__fopen_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
