// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

int climbStairs(int n)
{
    static std::map<int, int> answerMap;
    if( n <= 3 ) return n;

    auto it = answerMap.find(n);
    if( it != answerMap.end() )
    {
        return it->second;
    }

    int lastIsSingle = climbStairs(n-2);
    int lastIsDouble = climbStairs(n-1);
    int answer = lastIsSingle + lastIsDouble;
    answerMap[n] = answer;
    return answer;
}

bool VerifyResultsDynamic1( int n, int expected )
{
    if( climbStairs(n) == expected )
        return true;

    return false;
}

void TestDynamic1()
{
    bool failed = false;
    if (!VerifyResultsDynamic1(3, 3)) failed = true;

    for( int i=0; i<50; i++)
    {
        std::cout << "stairs " << i << " " << climbStairs(i) << std::endl;
    }

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



