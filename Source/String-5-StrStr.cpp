// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>

bool CheckIfStringIsAt(std::string haystack, int start, string needle)
{
	for (int j = 1; j < needle.length(); j++)
	{
		if (haystack[start + j] != needle[j])
		{
			return false;
		}
	}
	return true;
}

int strStr(std::string haystack, string needle)
{
	if (needle.length() == 0)
		return 0;
	if (haystack.length() == 0)
		return -1;

	for (int i = 0; i < haystack.length(); i++)
	{
		if (needle[0] == haystack[i])
		{
			// Check if entire needle string is at haystack[i]
			if (CheckIfStringIsAt(haystack, i, needle))
			{
				// if it is, then return i;
				return i;
			}
			// if it isn't, then don't do anything.  keep looking in for loop
		}
	} 
	return -1;
}

bool VerifyResultsString5(string input, string input2, int expected)
{
	int output = strStr(input, input2);

	if (output != expected)
		return false;

	return true;
}

void TestString5()
{
	bool failed = false;
	if (!VerifyResultsString5("abcd", "bc", 1)) failed = true;
	if (!VerifyResultsString5("abcd", "", -1)) failed = true;
	if (!VerifyResultsString5("", "ab", -1)) failed = true;
	if (!VerifyResultsString5("abcd", "b", 1)) failed = true;

	if (failed)
		std::cout << "Failure!";
	else
		std::cout << "Success!";
}

