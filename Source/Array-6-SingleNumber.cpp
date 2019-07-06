// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

int cmpfunc(const void * a, const void * b) 
{
    return (*(int*)a - *(int*)b);
}

int singleNumber(int* nums, int numsSize) 
{
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    for( int i=0; i<numsSize; i += 2 )
    {
        if( i+1 >= numsSize )
        {
            return nums[i];
        }

        if( nums[i] != nums[i+1] )
        {
            return nums[i];
        }

    }

    return 0;
}

int singleNumberHelper(vector<int>& data)
{
    int num = singleNumber(data.data(), (int)data.size());
    return num;
}

bool VerifyResults6( vector<int> input, int numExpected )
{
    int num = singleNumberHelper(input);
    if( numExpected != num )
        return false;

    return true;
}

void TestArray6()
{
    bool failed = false;
    if (!VerifyResults6({ 2, 2, 5, 5, 1 }, 1)) failed = true;
    if (!VerifyResults6({ 2, 2, 5, 5, 6 }, 6)) failed = true;
    if (!VerifyResults6({ 2 }, 2)) failed = true;
    if (!VerifyResults6({ 1, 1, 3 }, 3)) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



