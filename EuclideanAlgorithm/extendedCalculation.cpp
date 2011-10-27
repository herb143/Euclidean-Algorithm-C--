/*
 *
 *  extendedCalculation.cpp
 *  EuclideanAlgorithm
 *
 *  Represents the calculation of the Extended Euclidean Algorithm.
 *
 */

#include <iostream>
#include <stdlib.h>
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "extendedCalculation.h"

extendedCalculation::extendedCalculation() // Default constructor -- WE DO NOT WANT THIS.
{
    std::cerr << "Error: Extended calculation initialized improperly!" << std::endl;
    exit(1);
}

extendedCalculation::extendedCalculation(int nA, int nB) // The correct constructor.
{
    int nAV = nA;
	int nBV = nB;
	if (nAV < 0) { nAV = nAV * -1; } // We only need positives for the extended algorithm.
	if (nBV < 0) { nBV = nBV * -1; }
    m_nA = nAV; // Set the values.
    m_nB = nBV;
    
    m_calculatedGCD = gcdCalculation(m_nA, m_nB);

}