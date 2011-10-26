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
#include <ctime>
#include <iomanip>
#include "argFunctions.h"

int nGreater(int nA, int nB) // Function for finding the greater of two numbers.
{
	if (nA > nB) { return nA; }
	if (nB > nA) { return nB; }
	if (nA == nB) { return nA; }
}

int nLesser(int nA, int nB) // Function for finding the lesser of two numbers.
{
	if (nA < nB) { return nA; }
	if (nB < nA) { return nB; }
	if (nA == nB) { return nA; }
}

int nQuotient(int nA, int nB) // A function for finding the quotient in integer division.
{
	
	if (nB == 0) // If we would end up dividing by zero...
	{
		std::cerr << "Error: " << nA << " ÷ 0 makes your CPU go :(" << std::endl;
		exit(1); // Error out.
	}
	if (nA == 0) { return 0; } // Zero divided by anything is always zero.
	return nA / nB; // This will drop the fraction every time, never rounding.
}

int nRemainder(int nA, int nB) // A function for finding the remainder when dividing two integers.
{
	return nA - (nB * nQuotient(nA, nB)); // Return the original value, minus the product of the divisor the integer quotient.	
}

inline void GCDVerbose(int nTheDividend, int nTheQuotient, int nTheDivisor, int nTheRemainder)
{
	std::cout << nTheDividend << " = " << nTheQuotient << "*" << nTheDivisor << "+" << nTheRemainder << std::endl;
}

int nGCD (int nAInput, int nBInput, bool bVerbose = false) // A function for finding the Greatest Common Divisor of two integers.
{
	int nAV = nAInput;
	int nBV = nBInput;
	if (nAInput < 0) { nAV = nAV * -1; } // We only need positives for the GCD.
	if (nBInput < 0) { nBV = nBV * -1; }
	int nA = nGreater(nAV, nBV); // Set up the values we will work with.
	int nB = nLesser(nAV, nBV);
	if (nA == nB) { return nA; } // They are equal and are their own GCD's.
	
	
	int nCommonDivisor = nB; // Our first divisor is B. Our first dividend is A.
	int nTheRemainder = nRemainder(nA, nB); // This is our first remainder.
	if (bVerbose) { GCDVerbose(nA, nQuotient(nA, nB), nCommonDivisor, nTheRemainder); }	
	
	if (nTheRemainder == 0) { return nB; } // If there is no remainder, then the smaller number is the GCD.
    
    
	while (nTheRemainder != 0) // Loop until we find the remainder.
	{
		int nextRemainder = nRemainder(nCommonDivisor, nTheRemainder); // The next remainder, when the remainder becomes the divisor and the divisor becomes the dividend.
		if (bVerbose) { GCDVerbose(nCommonDivisor, nQuotient(nCommonDivisor, nTheRemainder), nTheRemainder, nextRemainder); }
		if (nextRemainder == 0) // If the next remainder will equal zero...
		{
			if (bVerbose) { std::cout << "GCD(" << nAInput << "," << nBInput << ") = " << nTheRemainder << std::endl; } // Output the GCD.
			return nTheRemainder; // We've got ourselves the last non-zero remainder.
		}
		else // We're not at the last non-zero remainder yet...
		{
			nCommonDivisor = nTheRemainder; // The remainder becomes the divisor, the divisor becomes the dividend.
			nTheRemainder = nextRemainder; // Use the next remainder and continue until we hit the next non-zero remainder.
		}
	}
}

void testGCD(int iii, int bbb) // Test function.
{
	int nGCDV = nGCD(iii, bbb); // Find GCD.
	int nGCDWorks = iii / nGCDV;
	int nGCDWorks2 = bbb / nGCDV;
	if ((nGCDWorks2 * nGCDV != bbb) || (nGCDWorks * nGCDV != iii)) { // Verify GCD goes evenly into both.
		std::cerr << "Error! GCD of " << iii << " and " << bbb << " was computed as " << nGCDV << std::endl; exit(1); }
	
}

void testLoop() // Loops through the test function for every number combination 1 - 10000
{
    time_t start,end;
    long double count = 0;
    std::cout << "Testing..." << std::endl;
    time(&start);
	for (int iii = 1; iii <= 10000; iii++) {
		for (int bbb = 1; bbb <= 10000; bbb++)
		{
			testGCD(iii, bbb); // NOTE: Since this function is not verbose, it is not truly representative of the speed.
                               // Non-verbose GCD calculations are 99% faster, but this difference (1/500 of a percent of
                               // a second) is so negligible that, since verbose calculations are not used for mass computation,
                               // the effective speed is pretty much the same.
            count++;
		}
	}
    time(&end);
    int timediff = difftime(end, start);
    long double secondsPerCalc = timediff / count;
	// If the program didn't exit.
    std::cout << std::setprecision(16);
	std::cout << "All " << count << " tests completed sucessfully in " << timediff << " seconds." << std::endl;
    std::cout << "Each GCD took about " << secondsPerCalc << " seconds." << std::endl;
}

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
            nGCD(atoi(argv[2]), atoi(argv[3]), true);
			break; 
		case COMMAND_TEST:
            testLoop();
			break;
	}
	
	return 0;
}