/*
 *  argFunctions.cpp
 *  EuclideanAlgorithm
 *
 *  argMatch sees if an argument matches a string.
 *  argIsNum returns whether or not an argument can be converted to a number.
 *  argCheck checks for arguments to the program and returns type Command.
 */

#include <iostream>
#include "argFunctions.h"

bool argMatch(int argc, char * const argv[], int argNum, std::string argTarget)
{
	if (argc > argNum)
	{
		if (argv[argNum] == argTarget) { return true; }
	}
	return false; // Otherwise return false.
}

bool argIsNum(int argc, char * const argv[], int argNum)
{
    if (argc > argNum) // If there's enough.
    {
        int nValue = atoi(argv[argNum]);
        if (nValue == 0) { return false; } // Zero value means invalid or... zero... which we can't use.
        if (nValue == INT_MAX || nValue == INT_MIN) { return false; } // Out of range.
        else { return true; }
    }
    else { return false; }
}

Command argCheck(int argc, char * const argv[])
{
	if (argc == 1) { return UNKNOWN_COMMAND; }
    else if (argc == 2) { if (argMatch(argc, argv, 1, "--test")) { return COMMAND_TEST; } } // If we have 1 arg and it's test, then test.
	else if (argc == 4) // If we have 3 arguments.
    {    
        if (argMatch(argc, argv, 1, "--GCD") && argIsNum(argc, argv, 2) && argIsNum(argc, argv, 3)) { return COMMAND_GCD; }
    }
	else { return UNKNOWN_COMMAND; }
}