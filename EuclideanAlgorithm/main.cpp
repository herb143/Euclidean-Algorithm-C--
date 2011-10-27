/* 
 *	C++ Euclidean Algorithm 1.1
 *	by Herbie Gilman (and Euclid)
 *	10/24/2011
 *
 *	A set of functions used to find the Greatest Common Divisor of
 *	any two integers, with a commandline interface and a test program.
 *
 *	All inputs must be nonzero integers (any positive or negative signs
 *	will be removed). The numbers can not be greater than 2 billion due
 *	to C++ datatype limitations.
 *
 *
 *	A NOTE ON THE TEST PROGRAM:
 *	By running this in a commandline with the option --test you can
 *	access a function which will test my digital Euclidean algorithm
 *	with every integer combination between 1 and 1000 (1 million calcs.)
 *
 *
 */

#include <iostream>
#include <stdlib.h>
#include "argFunctions.h"
#include "numberFunctions.h"
#include "testFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"

int main(int argc, char * const argv[]) // Main function, of course.
{
	using namespace std;
	switch (argCheck(argc, argv))
	{
		case UNKNOWN_COMMAND:
            cerr << "Proper usage is: EuclideanAlgorithm <options> [INT1] [INT2]" << endl;
            cerr << "OPTIONS: --GCD <INT1> <INT2>" << endl;
            cerr << "               finds the GCD of the two integer inputs." << endl;
            cerr << "         --test" << endl;
            cerr << "               GCD's all integer combinations between 1 and 10,000." << endl;
            cerr << endl;
            cerr << "------ EUCLIDEAN ALGORITHM 1.1 ------" << endl;
            cerr << "------- by Herbert F. Gilman --------" << endl;
			exit (1);
			break; 
        case COMMAND_GCD:
            gcdCalculation myCalculation(atoi(argv[2]), atoi(argv[3])); // Calculate the GCD.
            myCalculation.prettyPrint(); // Pretty print it.
			break; 
		case COMMAND_TEST:
             testLoop();
			break;
	}
	
	return 0;
}