/*
 *  numberFunctions.h
 *  EuclideanAlgorithm
 *
 *  nGreater, nLesser, nQuotient, nRemainder are all pretty self-explanatory.
 *  GCDVerbose is used for verbosity when calculating the GCD.
 *  nGCD calculates... well... the GCD.
 */

#ifndef EuclideanAlgorithm_numberFunctions_h
#define EuclideanAlgorithm_numberFunctions_h

int nGreater(int nA, int nB);
int nLesser(int nA, int nB);
int nQuotient(int nA, int nB);
int nRemainder(int nA, int nB);
inline void GCDVerbose(int nTheDividend, int nTheQuotient, int nTheDivisor, int nTheRemainder);
int nGCD (int nAInput, int nBInput, bool bVerbose = false);



#endif
