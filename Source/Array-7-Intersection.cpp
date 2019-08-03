// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

int cmpfunc2(const void * a, const void * b) 
{
    int va = *(const int*)a;
    int vb = *(const int*)b;
    return (va > vb) - (va < vb);
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
    if( nums1.size() == 0 || 
        nums2.size() == 0 )
    {
        return vector<int>();
    }

    qsort(nums1.data(), nums1.size(), sizeof(int), cmpfunc2);
    qsort(nums2.data(), nums2.size(), sizeof(int), cmpfunc2);

    vector<int> output;

    int i = 0;
    int j = 0;

    while(true)
    {
        if( j == nums2.size() ||
            i == nums1.size() )
        {
            break;
        }

        if( nums1[i] > nums2[j] )
        {
            j++;
        }
        else if( nums1[i] == nums2[j] )
        {
            output.push_back(nums2[j]);
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    return output;
}

bool VerifyResults7( vector<int> input1, vector<int> input2, vector<int> output )
{
    vector<int> returnVec = intersect(input1, input2);
    if (returnVec.size() != output.size())
        return false;

    for (size_t i = 0; i < output.size(); i++)
    {
        if (returnVec[i] != output[i]) return false;
    }

    return true;
}

void TestArray7()
{
    bool failed = false;
    //if (!VerifyResults7({ 1, 2, 2, 1 }, {2, 2}, {2, 2})) failed = true;
    if (!VerifyResults7({ 4, 1, 2, 2, 1 }, { 2, 2, 3 }, { 2, 2 })) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



