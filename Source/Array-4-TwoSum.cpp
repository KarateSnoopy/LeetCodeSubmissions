// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for(int i = 0; i < numsSize; i++)
    {
        for (int j = i+1; j < numsSize; j++)
        {
            int addedNumber;
            addedNumber = nums[i] + nums[j];
            if( addedNumber == target )
            {
                int outputSize = 2;
                *returnSize = outputSize;
                int* outputIndexArray = (int*)malloc(outputSize * sizeof(int));
                outputIndexArray[0] = i;
                outputIndexArray[1] = j;
                return outputIndexArray;
            }
        }
    }

    *returnSize = 0;
    return nullptr;
}

vector<int> twoSumHelper(vector<int>& data, int k)
{
    int returnSize = 0;
    int* returnData = twoSum(data.data(), (int)data.size(), k, &returnSize);

    vector<int> returnVec;
    for( int i=0; i<returnSize; i++ )
    {
        returnVec.push_back(returnData[i]);
    }
    if( returnData != nullptr ) free(returnData);

    return returnVec;
}

bool VerifyResults4( vector<int> input, int target, vector<int> output )
{
    vector<int> returnVec = twoSumHelper(input, target);
    if( returnVec.size() != output.size() )
        return false;

    for(size_t i=0; i<output.size(); i++)
    {
        if( returnVec[i] != output[i] ) return false;
    }

    return true;
}

void TestArray4()
{
    bool failed = false;
    if (!VerifyResults4({ 2, 7, 11, 15 }, 13, { 0, 2 })) failed = true;
    if (!VerifyResults4({ 1, 2, 3 }, 5, { 1, 2 })) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}


