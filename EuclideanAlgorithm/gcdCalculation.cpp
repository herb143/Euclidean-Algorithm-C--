/*
 *
 *  gcdCalculation.cpp
 *  EuclideanAlgorithm
 *
 *  Represents the calculation for a GCD.
 *
 */

#include <iostream>
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"

gcdCalculation::gcdCalculation() // Default constructor. WE DO NOT WANT THIS.
{
    std::cerr << "Error: GCD calculation initialized improperly!" << std::endl;
    exit(1);
}

gcdCalculation::gcdCalculation(int nA, int nB) // Proper constructor.
{
    
    m_nLines = 0; // Initialize nLines.
    m_lineArray = new EuclideanLine[m_nLines]; // Dynamic array with the size of nLines.
    int nAV = nA;
	int nBV = nB;
	if (nAV < 0) { nAV = nAV * -1; } // We only need positives for the GCD.
	if (nBV < 0) { nBV = nBV * -1; }
    m_nA = nAV; // Set the values.
    m_nB = nBV;
    
    m_nLines = 1; // We start the first line.
    m_lineArray[m_nLines - 1] = EuclideanLine(m_nA, m_nB); // Initialize the first line with the inputs.
    
    while (m_lineArray[m_nLines - 1].getRemainder() != 0) // While our remainder of the current line doesn't equal zero...
    {
        m_nLines++; // Create a new line.
        m_lineArray[m_nLines - 1] = EuclideanLine(m_lineArray[m_nLines - 2].getDiviser(), m_lineArray[m_nLines - 2].getRemainder());
    }
    
    m_nGCD = m_lineArray[m_nLines - 1].getDiviser(); // Set the GCD to the last nonzero remainder (a.k.a. the first zero-remainder diviser)
    
}

gcdCalculation::~gcdCalculation()
{
    delete[] m_lineArray; // Reallocate the memory.
    m_lineArray = 0; // Set the array to null, just in case.
}

EuclideanLine gcdCalculation::getLine(int lineNumber)
{
    if (m_nLines > lineNumber || lineNumber < 1)
    {
        std::cerr << "Error! Tried to access out-of-range GCD line!" << std::endl;
        exit(1);
    }
    return m_lineArray[lineNumber - 1];
}

void gcdCalculation::prettyPrint()
{
    for (int iii = 0; iii < m_nLines; iii++) // For every line in the algorithm.
    {
        m_lineArray[iii].prettyPrint(); // Pretty print the line.
    }
    std::cout << "GCD(" << m_nA << "," << m_nB << ") = " << m_nGCD << std::endl; // Print out the GCD as well.
}