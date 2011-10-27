/*
 *
 *  EuclideanLine.cpp
 *  EuclideanAlgorithm
 *
 *  Represents one line while working with the Euclidean algorithm.
 *
 */

#include <iostream>
#include <stdlib.h>
#include "numberFunctions.h"
#include "EuclideanLine.h"



EuclideanLine::EuclideanLine() // Default constructor. WE DO NOT WANT THIS.
{
    std::cerr << "Error: Line constructed without proper values!" << std::endl;
    exit(1);
}

EuclideanLine::EuclideanLine(int nDividend, int nDiviser) // Proper constructor.
{
    int nAV = nDividend;
	int nBV = nDiviser;
	if (nDividend < 0) { nAV = nAV * -1; } // We only need positives for the GCD.
	if (nDiviser < 0) { nBV = nBV * -1; }
	
    m_nDividend = nGreater(nAV, nBV); // Set up the values we will work with.
	m_nDiviser = nLesser(nAV, nBV);
    m_nQuotient = nQuotient(m_nDividend, m_nDiviser);
	m_nRemainder = m_nDividend - (m_nDiviser * m_nQuotient);
}

void EuclideanLine::prettyPrint()
{
    std::cout << m_nDividend << " = " << m_nQuotient << "*" << m_nDiviser << "+" << m_nRemainder << std::endl;
}