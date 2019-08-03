// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

int firstUniqChar(std::string input) 
{
    int* alphabet = new int[26] {}; 

    for(size_t i=0; i<input.length(); i++ )
    {
        char letter = input[i];
        if( letter >= 'a' && letter <= 'z' )
        {
            int indexIntoArray = letter - 'a';
            alphabet[indexIntoArray]++;
        }
    }

    for(size_t j=0; j<input.length(); j++ )
    {
        char letter = input[j];
        if( letter >= 'a' && letter <= 'z' )
        {
            int indexToArray = letter - 'a';
            if( alphabet[indexToArray] == 1 )
            {
                delete[] alphabet;
                return (int)j;
            }
        }
    }

    delete[] alphabet;
    return -1;
}

bool VerifyResultsString3( string input, int expected )
{
    int output = firstUniqChar(input);

    if( output != expected )
        return false;

    return true;
}

void TestString3()
{
    bool failed = false;
    if (!VerifyResultsString3("eleetcode", 1)) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}

