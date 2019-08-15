// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

uint64_t ConvertArrayToInt(vector<int>& input)
{
    uint64_t result = 0;
    for( int i=0; i<input.size(); i++)
    {
        result *= 10;
        result += input[i];
    }

    return result;
}

vector<int> ConvertIntToArray(uint64_t convertedInt)
{
    vector<int> result;

    while( convertedInt != 0 )
    {
        int lastDigit = convertedInt % 10;
        result.insert(result.begin(), lastDigit);
        convertedInt /= 10;
    }

    return result;
}

//vector<int> plusOne(vector<int>& input) 
//{
//    uint64_t convertedInt = ConvertArrayToInt( input );
//    convertedInt++;
//    vector<int> result = ConvertIntToArray(convertedInt);
//    return result;
//}

vector<int> plusOne(vector<int>& input)
{
    size_t i = input.size()-1;
    bool newDigit = false;

    while(input[i] == 9)
    {
        input[i] = 0;
        if( i != 0 )
        {
            i--;
        }
        else
        {
            input.insert(input.begin(), 1);
            newDigit = true;
            break;
        }
    }

    if( !newDigit )
    {
        input[i]++;
    }

    return input;
}

bool VerifyResults8( vector<int> input, vector<int> output )
{
    vector<int> returnVec = plusOne(input);
    if( returnVec.size() != output.size() )
        return false;

    for(size_t i=0; i<output.size(); i++)
    {
        if( returnVec[i] != output[i] ) return false;
    }

    return true;
}

void TestArray8()
{
    bool failed = false;
    if (!VerifyResults8({ 1, 2, 3 }, { 1, 2, 4 })) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}


