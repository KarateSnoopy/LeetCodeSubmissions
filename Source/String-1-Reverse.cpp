// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

void reverseString(vector<char>& s) 
{
    int j = 0;
    for( int i=(int)s.size()-1; i != 0; i--)
    {
        if (i == j || j > i)
        {
            break;
        }

        // swap s[0] and s[i]
        char temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
    }
}

bool VerifyResultsString1( vector<char> s, vector<char> expected )
{
    reverseString(s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != expected[i]) return false;
    }

    return true;
}

void TestString1()
{
    bool failed = false;
    //if (!VerifyResultsString1({ 'h', 'e', 'l', 'l', 'o' }, { 'o', 'l', 'l', 'e', 'h' })) failed = true;
    if (!VerifyResultsString1({ 'a', 'b', 'c', 'd' }, { 'd', 'c', 'b', 'a', 'h' })) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



