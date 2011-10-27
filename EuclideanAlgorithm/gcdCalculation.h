/*
 *
 *  gcdCalculation.h
 *  EuclideanAlgorithm
 *
 *  Represents the calculation for a GCD.
 *
 */

#ifndef EuclideanAlgorithm_gcdCalculation_h
#define EuclideanAlgorithm_gcdCalculation_h

class gcdCalculation
{
private:
    int m_nA; // The values for which we find the GCD.
    int m_nB;
    int m_nGCD; // The GCD.
    
    int m_nLines; // The array for lines in the function.
    EuclideanLine *m_lineArray;
public:
    gcdCalculation(); // Default constructor.
    gcdCalculation(int nA, int nB); // Proper constructor.
    ~gcdCalculation(); // Destructor.
    
    // Getters.
    int getGCD() { return m_nGCD; }
    int getFirstValue() { return m_nA; }
    int getSecondValue() { return m_nB; }
    int getLines() { return m_nLines; }
    EuclideanLine getLine(int lineNumber);
    
    // Pretty printing.
    void prettyPrint();
};

#endif
