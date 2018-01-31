//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project Allocation Subsection Tests
//
// DESCRIPTION
// -----------
// The allocation implementation source file tests
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
void runTests(void);
void allocationSizeOneTest(void);
void allocationSizeOneKiloTest(void);
void freeSetPointerToNullTest(void);
void freeSizeOneTest(void);
void freeSizeOneKiloTest(void);
void runSrMallocTests(void);
void runSrFreeTests(void);

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
    
    printf("Running Tests For SR allocation library...\n");
    runSrMallocTests();
    runSrFreeTests();
    printf("... Done\n");
    
POST(
    ,TRUE)

void
    runSrMallocTests(
        void
    )
PRE(
    TRUE)
    
    printf("    Running tests for sr_malloc()...\n");
    allocationSizeOneTest();
    allocationSizeOneKiloTest();
    
POST(
    ,TRUE)

void
    allocationSizeOneTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing allocation of size one...\n");
    
    char* newBuffer = sr_malloc( 1 );
    assert( newBuffer > (char*) 0 );
    sr_free( &newBuffer );
    
POST(
    ,TRUE)

void
    allocationSizeOneKiloTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing allocation of size one kilobyte...\n");
    
    char* newBuffer = sr_malloc( 1000 );
    assert( newBuffer > (char*) 0 );
    sr_free( &newBuffer );
    
POST(
    ,TRUE)

void
    runSrFreeTests(
        void
    )
PRE(
    TRUE)
    
    printf("    Running tests for sr_free()...\n");
    freeSetPointerToNullTest();
    freeSizeOneTest();
    freeSizeOneKiloTest();
    
POST(
    ,TRUE)

void
    freeSetPointerToNullTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing set pointer to null after free...\n");
    
    char* newBuffer = sr_malloc( 1 );
    sr_free( &newBuffer );
    assert( newBuffer == NULL );
    
POST(
    ,TRUE)

void
    freeSizeOneTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing deallocation of size one kilobyte...\n");
    
    char* newBuffer = sr_malloc( 1 );
    sr_free( &newBuffer );
    assert( newBuffer == NULL );
    
POST(
    ,TRUE)

void
    freeSizeOneKiloTest(
        void
    )
PRE(
    TRUE)
    
    printf("        testing deallocation of size one kilobyte...\n");
    
    char* newBuffer = sr_malloc( 1000 );
    sr_free( &newBuffer );
    assert( newBuffer == NULL );
    
POST(
    ,TRUE)
