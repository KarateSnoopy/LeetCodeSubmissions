// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdio.h>
#include <map>

void TestHailstone()
{
    uint64_t biggestStep = 0;
    uint64_t biggestI = 0;
    std::map<uint64_t, uint64_t> answerMap;
    for( uint64_t i = 1; i < 65000000; i++)
    {
        uint64_t number = i;
        uint64_t steps = 0;
        while (number != 1)
        {
            std::cout << number << ", ";
            if (number < 10000)
            {
                auto it = answerMap.find(number);
                if (it != answerMap.end())
                {
                    steps += it->second;
                    break;
                }
            }

            steps++;
            if (number % 2 == 0)
            {
                number /= 2;
            }
            else
            {
                number *= 3;
                number++;
            }
        }

        if (steps > biggestStep)
        {
            biggestStep = steps;
            biggestI = i;
        }

        if (i < 10000)
        {
            answerMap[i] = steps;
        }
        //std::cout << i << " = " << steps << " steps\n";
    }

    std::cout << "number " << biggestI << " was " << biggestStep << " steps\n";
    // will print out "number 63728127 was 949 steps"
    std::cout << "Done\n";
}



