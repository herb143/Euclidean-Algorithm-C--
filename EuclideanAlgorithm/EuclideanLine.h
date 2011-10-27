/*
 *
 *  EuclideanLine.cpp
 *  EuclideanAlgorithm
 *
 *  Represents one line while working with the Euclidean algorithm.
 *
 */

#ifndef EuclideanAlgorithm_EuclideanLine_h
#define EuclideanAlgorithm_EuclideanLine_h

class EuclideanLine
{
private:
    int m_nDividend;
    int m_nDiviser;
    int m_nQuotient;
    int m_nRemainder;
public:
    EuclideanLine(); // Default constructor.
    EuclideanLine(int nDividend, int nDiviser); // Proper constructor.
    
    // Getters.
    int getDividend() { return m_nDividend; }
    int getDiviser() { return m_nDiviser; }
    int getQuotient() { return m_nQuotient; }
    int getRemainder() { return m_nRemainder; }
    
    // Verbose function.
    void prettyPrint();
    
};

#endif
