#ifndef LISTOFNUMBERS_H
#define LISTOFNUMBERS_H

#include <iostream>
#include <vector>
#include <string>

#include <math.h>

class ListOfNumbers
{
public:
    ListOfNumbers();
    void menu();

private:
    void printNumbers(std::vector<long double> numbers_list);
    void calculateMean(std::vector<long double> numbers_list);
    void getLargestNumber(std::vector<long double> numbers_list);
    void getSmallestNumber(std::vector<long double> numbers_list);
    void countOccurences(std::vector<long double> numbers_list);
    std::vector<long double> addNumber(std::vector<long double> numbers_list);

};

#endif // LISTOFNUMBERS_H

