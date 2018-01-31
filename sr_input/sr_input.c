//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project Input Subsection
//
// DESCRIPTION
// -----------
// The input implementation source file
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
int validInputCharacter( int inputCharacter );
void clearInputBuffer( void );
int fillInputBuffer( char* inputBuffer, int amount );
int finishCharacter( int inputCharacter );

//-----------------------------------------------------------------------------------------
// EXPORTED FUNCTIONS
//-----------------------------------------------------------------------------------------

// They themselves will be in charge of malloc and free
// We will still leave the user in charge of malloc and free, and we will document this in
// the universal header file
int
    sr_getinput(
        int amount,
        char** inputBufferPointer
    )
PRE(
    inputBufferPointer != NULL &&
    *inputBufferPointer != NULL &&
    amount > 0)
    
    int numberOfInputCharactersRead = 0;
    
    numberOfInputCharactersRead = fillInputBuffer( *inputBufferPointer, amount );
    
POST(
    numberOfInputCharactersRead
    ,TRUE)

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTIONS
//-----------------------------------------------------------------------------------------

int fillInputBuffer( char* inputBuffer, int amount )
PRE(
    inputBuffer != NULL &&
    amount >= 0)
    
    int inputCharacter = 0;
    int inputBufferPosition = 0;
    
    inputCharacter = sr_getchar();
    while( validInputCharacter( inputCharacter ) && inputBufferPosition < amount )
    {
        inputBuffer[ inputBufferPosition++ ] = inputCharacter;
        inputCharacter = sr_getchar();
    }
    
    if( !finishCharacter( inputCharacter ) ) {
        clearInputBuffer();
    }
    
POST(
    inputBufferPosition,
    inputBufferPosition >= 0)

int
    finishCharacter(
        int inputCharacter
    )
PRE(
    inputCharacter > 0)
    
    int finished = UNDEFINED;
    
    if( inputCharacter == EOF || inputCharacter == '\n' ) {
        finished = VALID;
    } else {
        finished = INVALID;
    }
    
POST(
    finished
    ,TRUE)
int
    validInputCharacter(
        int inputCharacter
    )
PRE(
    inputCharacter > 0)
    
    int validity = UNDEFINED;
    
    if( inputCharacter != EOF && inputCharacter != '\n' ) {
        validity = VALID;
    } else {
        validity = INVALID;
    }
    
POST(
    validity
    ,TRUE)

int
    sr_getchar(
        void
    )
PRE(
    TRUE)
    
    int inputCharacter = 0;
    
    inputCharacter = getchar();
    
POST(
    inputCharacter
    ,TRUE)

void
    clearInputBuffer(
        void
    )
PRE(
    TRUE)
    
    while( getchar() != '\n' ) {}
    
POST(
    ,TRUE)


