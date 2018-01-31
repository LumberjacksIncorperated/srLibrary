//-----------------------------------------------------------------------------------------
//
// PROJECT
// -------
// The SR Library Project Allocation Subsection
//
// DESCRIPTION
// -----------
// The allocation implementation source file
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

// SR Library Main and Interface
#include "srLibrary.h"

//-----------------------------------------------------------------------------------------
// DEFINITIONS
//-----------------------------------------------------------------------------------------
typedef struct allocationNode_t {
    char* memoryPointer;
    int memorySize;
    struct allocationNode_t* next;
} allocationNode;

allocationNode* allocationList = NULL;

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTION FORWARD DEFINITIONS
//-----------------------------------------------------------------------------------------
void freeAllocationNode( allocationNode* node );
void freeNode( allocationNode* node );
void removeNodeFromList( allocationNode* node );
allocationNode* findNodeForMemory( char* memoryPointer );
char* addBufferToAllocationList( char* buffer, int size );
void addNodeToAllocationList( allocationNode* newNode );
void setPointerToNull( char** memoryPointer );
void freeNodeForMemory( char* memoryPointer );
void wipeNodeMemory( allocationNode* node );
void rejoinList( allocationNode* currentNode, allocationNode* previousNode );
void initializeAllocationNodeWithData( allocationNode* node, char* memoryPointer, int size );
void wipeWithZeroAndOne(char* memory, int size);

//-----------------------------------------------------------------------------------------
// EXPORTED FUNCTIONS
//-----------------------------------------------------------------------------------------
char*
    sr_malloc(
        int sizeRequired
    )
PRE(
    sizeRequired > 0)
    
    char* newBuffer = NULL;
    
    newBuffer = malloc( sizeRequired );
    if( sr_successfullyAllocated( newBuffer ) ) {
        newBuffer = addBufferToAllocationList( newBuffer, sizeRequired );
    } else {
        newBuffer = (char*) FAILED_ALLOCATION;
    }
    
POST(
    newBuffer
    ,newBuffer != NULL)

void
    sr_free(
        char** memoryPointer
    )
PRE(
    memoryPointer != NULL &&
    *memoryPointer != NULL)
    
    freeNodeForMemory( *memoryPointer );
    setPointerToNull( memoryPointer );
    
POST(
    ,*memoryPointer == NULL)

//-----------------------------------------------------------------------------------------
// PRIVATE FUNCTIONS
//-----------------------------------------------------------------------------------------
void
    setPointerToNull(
        char** memoryPointer
    )
PRE(
    memoryPointer != NULL &&
    *memoryPointer != NULL)
    
    *memoryPointer = NULL;
    
POST(
    ,*memoryPointer == NULL)

void
    freeNodeForMemory(
        char* memoryPointer
    )
PRE(
    memoryPointer != NULL)
    allocationNode* node = NULL;
    
    node = findNodeForMemory( memoryPointer );
    if( node != NULL ) {
        freeAllocationNode( node );
    }
    
POST(
    ,TRUE)

void
    freeAllocationNode(
        allocationNode* node
    )
PRE(
    node != NULL)
    
    wipeNodeMemory( node );
    freeNode( node );
    removeNodeFromList( node );
    
POST(
    ,TRUE)

void
    wipeNodeMemory(
        allocationNode* node
    )
PRE(
    node != NULL)
    
    int wipeCounter = 0;
    
    while( wipeCounter < 250000 ) {
        wipeWithZeroAndOne( node->memoryPointer, node->memorySize );
        wipeCounter++;
    }
    
POST(
    , TRUE)

void wipeWithZeroAndOne(char* memory, int size)
{
    memset(memory, 'a', size);
    memset(memory, 'g', size);
    memset(memory, 'h', size);
    memset(memory, 'r', size);
}

void
    freeNode(
        allocationNode* node
    )
PRE(
    node != NULL)
    
    free(node->memoryPointer);
    
POST(
    ,TRUE)

void
    removeNodeFromList(
        allocationNode* node
    )
PRE(
    node != NULL)
    
    allocationNode* currentNode = allocationList;
    allocationNode* previousNode = NULL;
    
    while( currentNode != node && currentNode != NULL)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    rejoinList( currentNode, previousNode );
    
POST(
    ,TRUE)

void
    rejoinList(
        allocationNode* currentNode,
        allocationNode* previousNode
    )
PRE(
    TRUE)
    
    if(currentNode != NULL)
    {
        if(previousNode == NULL)
        {
            allocationList = currentNode->next;
        } else {
            previousNode->next = currentNode->next;
        }
        free(currentNode);
    }
    
POST(
    ,TRUE)

allocationNode*
    findNodeForMemory(
        char* memoryPointer
    )
PRE(
    memoryPointer != NULL)
    
    allocationNode* currentNode = allocationList;
    allocationNode* foundNode = NULL;
    
    while(currentNode != NULL)
    {
        if( currentNode->memoryPointer = memoryPointer )
        {
             foundNode = currentNode;
        }
        currentNode = currentNode->next;
    }
    
POST(
    foundNode
    ,TRUE)

char*
    addBufferToAllocationList(
        char* buffer,
        int size
    )
PRE(
    buffer != NULL)
    
    allocationNode* newAllocationNode = malloc( sizeof( struct allocationNode_t ) );
    char* bufferToReturn = NULL;
    
    if( sr_successfullyAllocated( (char*) newAllocationNode ) )
    {
        initializeAllocationNodeWithData( newAllocationNode, buffer, size );
        addNodeToAllocationList( newAllocationNode );
        bufferToReturn = buffer;
    } else {
        bufferToReturn = (char*) FAILED_ALLOCATION;
        free( buffer );
    }
    
POST(
    bufferToReturn
    ,TRUE)

void
    initializeAllocationNodeWithData(
        allocationNode* node,
        char* memoryPointer,
        int size
    )
PRE(
    node != NULL &&
    memoryPointer != NULL &&
    size != 0)
    
    node->memoryPointer = memoryPointer;
    node->memorySize = size;
    node->next = NULL;
    
POST(
    ,TRUE)

void
    addNodeToAllocationList(
        allocationNode* newNode
    )
PRE(
    newNode != NULL)
    
    if( allocationList == NULL )
    {
        allocationList = newNode;
    } else {
        newNode->next = allocationList;
        allocationList = newNode;
    }
    
POST(
    ,TRUE)
