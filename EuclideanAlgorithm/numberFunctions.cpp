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

inline void GCDVerbose(int nTheDividend, int nTheQuotient, int nTheDivisor, int nTheRemainder)
{
	std::cout << nTheDividend << " = " << nTheQuotient << "*" << nTheDivisor << "+" << nTheRemainder << std::endl;
}

int nGCD (int nAInput, int nBInput, bool bVerbose) // A function for finding the Greatest Common Divisor of two integers.
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