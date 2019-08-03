// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void rotate(int* nums, int numsSize, int k) 
{
    if(numsSize <= 1)
    {
        return;
    }

    int indexAtEndOfArray = numsSize - 1;

    k %= numsSize;

    while( k>0 )
    {
        int notEraseData = nums[indexAtEndOfArray];
        for (int i = numsSize - 1; i > 0; --i)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = notEraseData;
        k--;
    }
}

void rotateHelper(vector<int>& data, int k)
{
    rotate(data.data(), (int)data.size(), k);
}

bool VerifyResults( vector<int> input, int k, vector<int> output )
{
    rotateHelper(input, k);
    if( input.size() != output.size() )
        return false;

    for(size_t i=0; i<output.size(); i++)
    {
        if( input[i] != output[i] ) return false;
    }

    return true;
}

void TestArray3()
{
    bool failed = false;
    if (!VerifyResults({ 1 }, 1, { 1 })) failed = true;
    if (!VerifyResults({ 1,2,3,4 }, 1, { 4,1,2,3 })) failed = true;
    if (!VerifyResults({ 1,2,3,4 }, 2, { 3,4,1,2 })) failed = true;
    if (!VerifyResults({ 1,2,3,4 }, 3, { 2,3,4,1 })) failed = true;
    if (!VerifyResults({ 1,2,3,4 }, 4, { 1,2,3,4 })) failed = true;
    if (!VerifyResults({ 1,2,3,4 }, 8, { 1,2,3,4 })) failed = true;
    if (!VerifyResults({ 1,2,3,4 }, 5, { 4,1,2,3 })) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}


