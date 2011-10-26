/*
 *  argFunctions.cpp
 *  EuclideanAlgorithm
 *
 *  The Command enum is for the various commands which could be passed to the program.
 *  argMatch sees if an argument matches a string.
 *  argIsNum returns whether or not an argument can be converted to a number.
 *  argCheck checks for arguments to the program and returns type Command.
 */

#ifndef EuclideanAlgorithm_argFunctions_h
#define EuclideanAlgorithm_argFunctions_h

enum Command
{
	UNKNOWN_COMMAND,
	COMMAND_GCD,
	COMMAND_TEST
};

bool argMatch(int argc, char * const argv[], int argNum, std::string argTarget);
bool argIsNum(int argc, char * const argv[], int argNum);
Command argCheck(int argc, char * const argv[]);

#endif
