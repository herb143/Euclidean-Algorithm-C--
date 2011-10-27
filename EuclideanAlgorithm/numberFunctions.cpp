/*
 *  numberFunctions.cpp
 *  EuclideanAlgorithm
 *
 *  nGreater, nLesser, nQuotient, nRemainder are all pretty self-explanatory.
 *  GCDVerbose is used for verbosity when calculating the GCD.
 *  nGCD calculates... well... the GCD.
 */


#include <iostream>
#include "numberFunctions.h"

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
