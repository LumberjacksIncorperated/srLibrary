#ifndef SR_LIBRARY_H
#define SR_LIBRARY_H
//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project
//
// DESCRIPTION
// -----------
// The library implementation header file
//
// AUTHOR
// ------
// Lumberjacks Incorperated (2018)
//
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
// TYPE DEFINITIONS
//-----------------------------------------------------------------------------------------
typedef int SR_ERROR;

//-----------------------------------------------------------------------------------------
// VALUE DEFINITIONS DEFINITIONS
//-----------------------------------------------------------------------------------------

// SR Error Definitions
#define SR_OK                                   0
#define SR_FAIL                                 1

// SR Library Definitions
#define UNDEFINED                               -1
#define INVALID_BUFFER                          (char*) 1
#define VALID                                   1
#define INVALID                                 0

// For SR Malloc and SR Free
#define FAILED_ALLOCATION                       1

// Pre And Post Condition Definitions
#define PRECONDITION(X)                         assert((X))
#define POSTCONDITION(X)                        assert((X))
#define POST(__return, __postcond)              POSTCONDITION( __postcond ); return __return; }
#define PRE(__precond)                          { PRECONDITION( __precond );
#define TRUE                                    1

//-----------------------------------------------------------------------------------------
// EXPORTED FUNCTIONS
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_getinput
//
// DESCRIPTION:
//                  retrieves a specified number of characters from standard input
//
// PARAMETERS:
//                  char**
//                                  inputBuffer
//                                                      A pointer to a buffer that has
//                                                      been allocated
//
// RETURNS:
//                  int                  the number of characters read
//
//
//-----------------------------------------------------------------------------------------
int
    sr_getinput(
        int amount,
        char** inputBufferPointer
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_successfulyAllocated
//
// DESCRIPTION:
//                  Check whether after a malloc a pointer has been successfully allocated
//
// PARAMETERS:
//                  char*
//                                  inputBuffer
//                                                      Buffer that has been allocated
//
// RETURNS:
//                  0                    on failed allocated
//                  1                    on successful allocation
//
//
//-----------------------------------------------------------------------------------------
int
    sr_successfulyAllocated(
        char* inputBuffer
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_strlen
//
// DESCRIPTION:
//                  The SR (safe) implementation of the standard 'strlen'
//
// PARAMETERS:
//                  char*
//                                  inputBuffer
//                                                      A buffer which contains the string
//                                                      to measure
//
// RETURNS:
//                  int                     The size of the string inputted
//
//
//-----------------------------------------------------------------------------------------
int
    sr_strlen(
        char* inputBuffer
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_allocate
//
// DESCRIPTION:
//                  The SR (safe) implementation of the standard 'malloc'
//
// PARAMETERS:
//                  int
//                                  sizeRequired
//                                                          The size to allocate
//
// RETURNS:
//                  SR_OK                   on success
//                  INVALID_BUFFER          if not enough memory was avaliable to allocate
//
//-----------------------------------------------------------------------------------------
char*
    sr_allocate(
        int sizeRequired
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_getchar
//
// DESCRIPTION:
//                  The SR (safe) implementation of the standard 'getchar'
//
// PARAMETERS:
//                  void
//
// RETURNS:
//                  int                     ASCII for character, or EOF on file end or
//                                          error
//
//-----------------------------------------------------------------------------------------
int
    sr_getchar(
        void
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_malloc
//
// DESCRIPTION:
//                  The SR (safe) implementation of the standard 'malloc'
//
// PARAMETERS:
//                  int
//                                  sizeRequired
//                                                      The size of buffer to be allocated
//
// RETURNS:
//                  INVALID_BUFFER       on failed allocated
//                  !INVALID_BUFFER      on successful allocation
//
//-----------------------------------------------------------------------------------------
char*
    sr_malloc(
        int sizeRequired
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_free
//
// DESCRIPTION:
//                  The SR (safe) implementation of the standard 'free'
//
// PARAMETERS:
//                  char**
//                                  memoryPointer
//                                                      A pointer to the buffer vairable to
//                                                      be allocated
//
// RETURNS:
//                  int                     ASCII for character, or EOF on file end or
//                                          error
//
//-----------------------------------------------------------------------------------------
void
    sr_free(
        char** memoryPointer
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_increment
//
// DESCRIPTION:
//                  safely increments an integer
//
// PARAMETERS:
//                  int*
//                                  integerPointer
//                                                      Pointer to integer to be incremented
//
// RETURNS:
//
//-----------------------------------------------------------------------------------------
void
    sr_increment(
        int* integerPointer
    );

//-----------------------------------------------------------------------------------------
//
// NAME:
//                  sr_add
//
// DESCRIPTION:
//                  safely add two integers together
//
// PARAMETERS:
//                  int
//                                  operandOne
//                                                      The first of two integers to be
//                                                      added
//                  int
//                                  operandtwo
//                                                      The second of two integers to be
//                                                      added
//
// RETURNS:
//                  int                                 the result of the addition
//
//-----------------------------------------------------------------------------------------
int
    sr_add(
        int operandOne,
        int operandTwo
    );

#endif
