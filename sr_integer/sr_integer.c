//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project Integer Subsection
//
// DESCRIPTION
// -----------
// The integer implementation source file
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
#include "limits.h"

// Interface File
#include "srLibrary.h"

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTION FORWARD DEFINITIONS
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// EXPORTED FUNCTIONS
//-----------------------------------------------------------------------------------------

void
    sr_increment(
        int* integerPointer
    )
PRE(
    integerPointer != NULL &&
    *integerPointer < INT_MAX)
    
    int integer = *integerPointer;
    int incrementedInteger = integer + 1;
    *integerPointer = incrementedInteger;
    
POST(
    ,TRUE)

int
    sr_add(
        int operandOne,
        int operandTwo
    )
PRE(
    TRUE)
    
    int additionResult = 0;
    
    if( operandTwo < 0 )
    {
        while( operandTwo < 0 ) {
            assert( operandOne > INT_MIN );
            operandOne = operandOne - 1;
            operandTwo = operandTwo + 1;
        }
    } else {
        while( operandTwo > 0 ) {
            assert( operandOne < INT_MAX );
            operandOne = operandOne + 1;
            operandTwo = operandTwo - 1;
        }
    }
    additionResult = operandOne;
    
POST(additionResult
    ,TRUE)

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTIONS
//-----------------------------------------------------------------------------------------
