#!/bin/bash

#------------------------------------------------------------------------------------------
#*
#* PROJECT
#* -------
#* Project 'SR Library Tests'
#*
#* PURPOSE
#* -------
#* To setup, and run tests for the current implementation of the sr library
#*
#* AUTHOR
#* ------
#* Lumberjacks Incorperated (2018)
#*
#------------------------------------------------------------------------------------------

#------------------------------------------------------------------------------------------
# MAIN
#------------------------------------------------------------------------------------------
main()
{
    srAllocationTests
    srInputTests
    srIntegerTests
}

#------------------------------------------------------------------------------------------
# INTERNAL FUNCTIONS
#------------------------------------------------------------------------------------------
function srIntegerTests()
{
    compileSrIntegerTests
    runSrIntegerTests
}

function compileSrIntegerTests()
{
    gcc -I./ srLibrary.c sr_integer/sr_integerTest.c sr_integer/sr_integer.c sr_input/sr_input.c  sr_allocation/sr_allocation.c -W -o testInteger
}

function runSrIntegerTests()
{
    ./testInteger
    rm testInteger
}

function srInputTests()
{
    compileSrInputTests
    runSrInputTests
}

function compileSrInputTests()
{
    gcc -I./ srLibrary.c sr_input/sr_inputTest.c sr_input/sr_input.c  sr_allocation/sr_allocation.c -W -o testInput
}

function runSrInputTests()
{
    ./testInput
    rm testInput
}

function srAllocationTests()
{
    compileSrAllocationTests
    runSrAllocationTests
}

function compileSrAllocationTests()
{
    gcc -I./ srLibrary.c sr_allocation/sr_allocationTest.c  sr_allocation/sr_allocation.c -W -o testAllocation
}

function runSrAllocationTests()
{
    ./testAllocation
    rm testAllocation
}

#------------------------------------------------------------------------------------------
# SCRIPT
#------------------------------------------------------------------------------------------
    main
