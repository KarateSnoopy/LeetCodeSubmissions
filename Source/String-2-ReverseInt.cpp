// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

int reverseInt(int input) 
{
    std::string protoArray = std::to_string(input);

	size_t j = 0;
    if( input < 0)
    {
        j++;
    }
    int temp = 0;
    for(size_t i=protoArray.length()-1; i > 0; i--)
    {
        if( j >= i )
        {
            break;
        }

        temp = protoArray[j];
        protoArray[j] = protoArray[i];
        protoArray[i] = temp;
        j++;
    }

    long long return1 = std::atoll(protoArray.c_str());
    if( return1 > std::numeric_limits<int>::max() || 
        return1 < std::numeric_limits<int>::min() )
    {
        return 0;
    }

    return (int)return1;
}

bool VerifyResultsString2( int input, int expected )
{
    int output = reverseInt(input);

    if( output != expected )
        return false;

    return true;
}

void TestString2()
{
    bool failed = false;
    //if (!VerifyResultsString2(123, 321)) failed = true;
    //if (!VerifyResultsString2(-123, -321)) failed = true;
    //if (!VerifyResultsString2(120, 021)) failed = true;
    if (!VerifyResultsString2(1534236469, 0)) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



