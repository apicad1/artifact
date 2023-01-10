/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_44.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
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
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#ifndef OMITBAD

static void badSink(int data)
{
    if (data != -1)
    {
        /* FLAW: Attempt to close the file using fclose() instead of close() */
        fclose((FILE *)data);
    }
}

void CWE404_Improper_Resource_Shutdown__open_fclose_44_bad()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = badSink;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink(int data)
{
    if (data != -1)
    {
        /* FIX: Close the file using close() */
        CLOSE(data);
    }
}

static void goodB2G()
{
    int data;
    void (*funcPtr) (int) = goodB2GSink;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    funcPtr(data);
}

void CWE404_Improper_Resource_Shutdown__open_fclose_44_good()
{
    goodB2G();
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
    CWE404_Improper_Resource_Shutdown__open_fclose_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
