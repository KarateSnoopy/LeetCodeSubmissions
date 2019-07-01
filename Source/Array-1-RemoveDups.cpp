// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


int removeDuplicates(int* nums, int numsSize) 
{
    if (numsSize <= 1 || nums == NULL)
    {
        return numsSize;
    }

    int oldLength = numsSize;
    int* p1 = nums + 0;
    int* p2 = nums + 0;
    int newLength = 1;

    while (p2 < nums + numsSize) // p2 < nums[1] if numsSize == 2
    {
        if (*p1 == *p2)
        {
            p2++;
        }
        else
        {
            p1++;
            *p1 = *p2;
            newLength++;
            if (p2 == nums + numsSize - 1)
            {
                break;
            }
            p2++;
        }
    }

    return newLength;
}

bool VerifyResult( std::vector<int> input, std::vector<int> expectedOutput )
{
    //std::cout << "Input: ";
    for (size_t i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << ", ";
    }
    std::cout << std::endl;

    int newLength = removeDuplicates(input.data(), input.size());

    std::cout << "Output: ";
    for (int i = 0; i < newLength; i++)
    {
        std::cout << input[i] << ", ";
    }
    std::cout << std::endl;

    if( newLength != expectedOutput.size() )
    {
        return false;
    }
    for (int i = 0; i < newLength; i++)
    {
        if( input[i] != expectedOutput[i] )
        {
            return false;
        }
    }

    return true;
}

void TestArray1()
{
    int nums[6] = { 7,1,5,3,9,4 };
    int length = 6;

    int biggestIndexSoFar = 0;
    int smallestIndexSoFar = 0;
    for (int i = 1; i < length; i++)
    {
        if (nums[biggestIndexSoFar] < nums[i])
        {
            biggestIndexSoFar = i;
        }

        if (nums[smallestIndexSoFar] > nums[i])
        {
            smallestIndexSoFar = i;
        }
    }



    bool failed = false;
    if (!VerifyResult({ }, { })) { std::cout << "Failed!"; failed = true; }
    if (!VerifyResult({ 1 }, { 1 })) { std::cout << "Failed!"; failed = true; }
    if (!VerifyResult({ 10,10 }, { 10 })) { std::cout << "Failed!"; failed = true; }
    if (!VerifyResult({ 1,1,1 }, { 1 })) { std::cout << "Failed!"; failed = true; }
    if (!VerifyResult({ 2,5,9 }, { 2,5,9 })) { std::cout << "Failed!"; failed = true; }
    if (!VerifyResult({ -10,-10,5,9 }, { -10,5,9 })) { std::cout << "Failed!"; failed = true; }
    if (!VerifyResult({ 1,1,2,2,3,3,5,5 }, { 1,2,3,5 })) { std::cout << "Failed!"; failed = true; }

    if( !failed ) std::cout << "Success!"; 
}
