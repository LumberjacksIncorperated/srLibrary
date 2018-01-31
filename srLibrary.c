//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project
//
// DESCRIPTION
// -----------
// The library implementation source file
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
#include <string.h>
#include <assert.h>

// Interface File
#include "srLibrary.h"

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTION FORWARD DEFINITIONS
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// EXPORTED FUNCTIONS
//-----------------------------------------------------------------------------------------
int
    sr_strlen (
        char* inputBuffer
    )
PRE(
    inputBuffer != NULL )
    
    int bufferLength = 0;
    
    bufferLength = strlen( inputBuffer );
    
POST(
    bufferLength
    ,TRUE)

char*
    sr_allocate (
        int sizeRequired
    )
PRE(
    sizeRequired > 0 )
    
    char* newBuffer = malloc( sizeRequired );
    
    if( !sr_successfullyAllocated( newBuffer ) ) {
        newBuffer = INVALID_BUFFER;
    }
    
POST(
    newBuffer
    ,newBuffer != NULL)

int
    sr_successfullyAllocated(
        char* buffer
    )
PRE(
    buffer != NULL)
    
    int allocationSuccessful = INVALID;
    
    if( buffer != NULL ) {
        allocationSuccessful = VALID;
    } else {
        allocationSuccessful = INVALID;
    }
    
POST(
    allocationSuccessful
    ,TRUE)

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTIONS
//-----------------------------------------------------------------------------------------




