/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_12.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * Sinks: type_overrun_memcpy
 *    GoodSink: Perform the memcpy() and prevent overwriting part of the structure
 *    BadSink : Overwrite part of the structure by incorrectly using the sizeof(struct) in memcpy()
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


void printLine (const char * line){}	// print line
int globalReturnsTrue() { return 1;}

int globalReturnsFalse() { return 0;}

int globalReturnsTrueOrFalse() { return (rand() % 2);}

#ifndef _WIN32
#include <wchar.h>
#endif

/* SRC_STR is 32 char long, including the null terminator, for 64-bit architectures */
#define SRC_STR "0123456789abcdef0123456789abcde"

typedef struct _charVoid
{
    char charFirst[16];
    void * voidSecond;
    void * voidThird;
} charVoid;

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid.voidSecond */
            printLine((char *)structCharVoid.voidSecond);
            /* FLAW: Use the sizeof(structCharVoid) which will overwrite the pointer voidSecond */
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)structCharVoid.charFirst);
            printLine((char *)structCharVoid.voidSecond);
        }
    }
    else
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid.voidSecond */
            printLine((char *)structCharVoid.voidSecond);
            /* FIX: Use sizeof(structCharVoid.charFirst) to avoid overwriting the pointer voidSecond */
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)structCharVoid.charFirst);
            printLine((char *)structCharVoid.voidSecond);
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
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid.voidSecond */
            printLine((char *)structCharVoid.voidSecond);
            /* FIX: Use sizeof(structCharVoid.charFirst) to avoid overwriting the pointer voidSecond */
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)structCharVoid.charFirst);
            printLine((char *)structCharVoid.voidSecond);
        }
    }
    else
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            /* Print the initial block pointed to by structCharVoid.voidSecond */
            printLine((char *)structCharVoid.voidSecond);
            /* FIX: Use sizeof(structCharVoid.charFirst) to avoid overwriting the pointer voidSecond */
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(char))-1] = '\0'; /* null terminate the string */
            printLine((char *)structCharVoid.charFirst);
            printLine((char *)structCharVoid.voidSecond);
        }
    }
}

void CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_12_good()
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
    CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
