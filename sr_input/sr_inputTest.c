//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project Input Subsection Tests
//
// DESCRIPTION
// -----------
// The input implementation source file tests
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
void runSrInputTests( void );
void inputSizeOneTest( void );
void inputSizeOneHundredTest( void );

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
    
    printf("Running Tests For SR input library...\n");
    runSrInputTests();
    printf("... Done\n");
    
POST(
    ,TRUE)

void
    runSrInputTests(
        void
    )
PRE(
    TRUE)
    
    printf("    Running tests for sr_getInput()...\n");
    inputSizeOneTest();
    inputSizeOneHundredTest();
    
POST(
    ,TRUE)

void
    inputSizeOneTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing sr_getInput() of size one...\n");
    printf("        (please enter characters)\n");
    printf("        ");
    
    char* newBuffer = sr_malloc( 2 );
    int amountRead = sr_getinput( 1, &newBuffer );
    newBuffer[ amountRead ] = 0;
    assert( amountRead >= 0 );
    assert( amountRead <= 1 );
    sr_free( &newBuffer );
    
POST(
    ,TRUE)

void
    inputSizeOneHundredTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing sr_getInput() of size one hundred...\n");
    printf("        (please enter characters)\n");
    printf("        ");
    
    char* newBuffer = sr_malloc( 101 );
    int amountRead = sr_getinput( 100, &newBuffer );
    newBuffer[ amountRead ] = 0;
    assert( amountRead >= 0 );
    assert( amountRead <= 100 );
    sr_free( &newBuffer );
    
POST(
    ,TRUE)
