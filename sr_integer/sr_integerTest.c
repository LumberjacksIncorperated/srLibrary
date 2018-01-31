//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project Integer Subsection Tests
//
// DESCRIPTION
// -----------
// The integer implementation source file tests
//
// AUTHOR
// ------
// Lumberjacks Incorperated (2018)
//
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// Interface File
#include "srLibrary.h"

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTION FORWARD DEFINITIONS
//-----------------------------------------------------------------------------------------
void runTests( void );
void runSrIncrementTests( void );
void runSrAddTests( void );
void integerIncrementOneTest( void );
void integerAddOneTest( void );

//-----------------------------------------------------------------------------------------
// TESTING DRIVER
//-----------------------------------------------------------------------------------------
int
    main(
        void
    )
PRE(
    TRUE)
    
    printf("\n");
    runTests();
    printf("\n");
    
POST(
    EXIT_SUCCESS
    ,TRUE)

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTIONS
//-----------------------------------------------------------------------------------------
void
    runTests(
        void
    )
PRE(
    TRUE)
    
    printf("Running Tests For SR integer library...\n");
    runSrIncrementTests();
    runSrAddTests();
    printf("... Done\n");
    
POST(
    ,TRUE)

void
    runSrAddTests(
        void
    )
PRE(
    TRUE)
    
    printf("    Running tests for sr_add()...\n");
    integerAddOneTest();
    
POST(
    ,TRUE)

void
    runSrIncrementTests(
        void
    )
PRE(
    TRUE)
    
    printf("    Running tests for sr_increment()...\n");
    integerIncrementOneTest();
    
POST(
    ,TRUE)

void
    integerIncrementOneTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing sr_increment applied to conforming input of one...\n");
    
    int integer = 1;
    sr_increment( &integer );
    assert( integer == 2 );
    
POST(
    ,TRUE)

void
    integerAddOneTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing sr_add applied to conforming input of one...\n");
    
    int operandOne = 1;
    int operandTwo = 1;
    int additionResult = 0;
    
    additionResult = sr_add( operandOne, operandTwo );
    assert( additionResult == 2 );
    
POST(
    ,TRUE)
