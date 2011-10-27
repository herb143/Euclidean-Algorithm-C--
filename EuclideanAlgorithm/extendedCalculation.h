/*
 *
 *  extendedCalculation.h
 *  EuclideanAlgorithm
 *
 *  Represents the calculation of the Extended Euclidean Algorithm.
 *
 */

#ifndef EuclideanAlgorithm_extendedCalculation_h
#define EuclideanAlgorithm_extendedCalculation_h

class extendedCalculation
{
private:
    int m_nA; // The two numbers to be calculated with
    int m_nB;
    
    gcdCalculation m_calculatedGCD;
    
public:
    extendedCalculation(); // Default constructor -- WE DO NOT WANT THIS.
    extendedCalculation(int nA, int nB);
};

#endif
