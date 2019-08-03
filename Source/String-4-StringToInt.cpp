// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

int myAtoi(std::string input) 
{
    int64_t answer = 0;

    bool isNeg = false;
    bool negOrPosHasBeenSeen = false;
    bool hasSeenNumbers = false;
    for( int i=0; i<input.length(); i++ )
    {
        if( !hasSeenNumbers && input[i] == '-' && !negOrPosHasBeenSeen)
        {
            isNeg = true;
            negOrPosHasBeenSeen = true;
            hasSeenNumbers = true;
        }
        else if (!hasSeenNumbers && input[i] == '+' && !negOrPosHasBeenSeen)
        {
            isNeg = false;
            negOrPosHasBeenSeen = true;
            hasSeenNumbers = true;
        }
        else if( (input[i] == ' ' || input[i] == '\t') && !hasSeenNumbers)
        {
            // Skip 
        }
        else if ((input[i] == ' ' || input[i] == '\t') && hasSeenNumbers)
        {
            if (isNeg)
            {
                answer *= -1;
            }

            return (int)answer;
        }
        else if(input[i] >= '0' && input[i] <= '9')
        {
            hasSeenNumbers = true;
            int64_t numDigit = input[i] - '0';
            answer *= 10;

            if (answer > INT_MAX && !isNeg)
                return INT_MAX;
            if (answer > INT_MAX && isNeg)
                return INT_MIN;

            answer += numDigit;
        }
        else if(input[i] == '.')
        {
            if (isNeg)
            {
                answer *= -1;
            }

            return (int)answer;
        }
        else if (!hasSeenNumbers) // invalid chars
        {
            return 0;
        }
        else
        {
            // Ignore invalid chars
            if (isNeg)
            {
                answer *= -1;
            }

            return (int)answer;
        }
    }

    if( isNeg )
    {
        answer *= -1;
    }

    if (answer > INT_MAX)
        return INT_MAX;
    if (answer < INT_MIN)
        return INT_MIN;

    return (int)answer;
}

bool VerifyResultsString4( string input, int expected )
{
    int output = myAtoi(input);

    if( output != expected )
        return false;

    return true;
}

void TestString4()
{
    bool failed = false;
    //if (!VerifyResultsString4("123", 123)) failed = true;
    //if (!VerifyResultsString4("-123", -123)) failed = true;
    //if (!VerifyResultsString4("\t-123", -123)) failed = true;
    //if (!VerifyResultsString4(" +123", 123)) failed = true;
    //if (!VerifyResultsString4("4193 with words", 4193)) failed = true;
    //if (!VerifyResultsString4("words and 987", 0)) failed = true;
    if (!VerifyResultsString4("-91283472332", INT_MIN)) failed = true;
    
    //if (!VerifyResultsString4("words and 0", 0)) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}

