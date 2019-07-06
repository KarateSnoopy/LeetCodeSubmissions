// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

bool containsDuplicate(int* nums, int numsSize) 
{
    for( int i = 0; i<numsSize; i++ )
    {
        for( int j = i+1; j<numsSize; j++)
        {
            if( nums[i] == nums[j] )
            {
                return true;
            }
        }
    }

    return false;
}


std::map<int, bool> g_map;
bool containsDuplicate2(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        if( g_map.find(nums[i]) != g_map.end() )
        {
            return true;
        }

        g_map[nums[i]] = true;
    }

    return false;
}


bool containsDuplicateHelper(vector<int>& data)
{
    bool dup = containsDuplicate2(data.data(), (int)data.size());
    return dup;
}

bool VerifyResults5( vector<int> input, bool dupExpected )
{
    bool hasDup = containsDuplicateHelper(input);
    if( dupExpected != hasDup )
        return false;

    return true;
}

void TestArray5()
{
    bool failed = false;
    if (!VerifyResults5({ 1, 2, 3 }, false)) failed = true;
    if (!VerifyResults5({ 1, 1, 3 }, true)) failed = true;
    if (!VerifyResults5({ 3, 1, 5, 1, 4 }, true)) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}




/*


class Solution {
public:
    std::map<int, bool> g_map;
    bool containsDuplicate2(int* nums, int numsSize)
    {
        for (int i = 0; i < numsSize; i++)
        {
            if( g_map.find(nums[i]) != g_map.end() )
            {
                return true;
            }

            g_map[nums[i]] = true;
        }

        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        return containsDuplicate2(nums.data(), (int)nums.size());
    }
};


*/