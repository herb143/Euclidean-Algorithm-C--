/*
 *  testFunctions.cpp
 *  EuclideanAlgorithm
 *
 *  testGCD creates a GCD and checks whether or not it divides in correctly.
 *  testLoop loops through this 100 million times, and times it.
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "numberFunctions.h"
#include "EuclideanLine.h"
#include "gcdCalculation.h"
#include "testFunctions.h"

void testGCD(int iii, int bbb) // Test function.
{
	gcdCalculation testCase(iii, bbb); // New GCD test case.
	int nGCDWorks = iii / testCase.getGCD();
	int nGCDWorks2 = bbb / testCase.getGCD();
	if ((nGCDWorks2 * testCase.getGCD() != bbb) || (nGCDWorks * testCase.getGCD() != iii)) { // Verify GCD goes evenly into both.
		std::cerr << "Error! GCD of " << iii << " and " << bbb << " was computed as " << testCase.getGCD() << std::endl; exit(1); }
	
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