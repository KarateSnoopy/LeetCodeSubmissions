// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
class Solution {
public:

    string getIgnoredLettersOfEmail(string email)
    {
        bool inDomain = false;
        bool inPlus = false;
        string result;
        for (size_t x = 0; x < email.length(); x++)
        {
            // cout << email[x] << endl;
            if (!inDomain)
            {
                // Process user name                
                if (email[x] == '@')
                {
                    inDomain = true;
                    result += email[x];
                }
                else if (email[x] == '.')
                {
                    // ignore
                }
                else if (email[x] == '+')
                {
                    inPlus = true;
                }
                else if (inPlus == false)
                {
                    result += email[x];
                }
            }
            else
            {
                // Process domain name                
                result += email[x];
            }
        }

        return result;
    }

    int numUniqueEmails(vector<string>& emails)
    {
        if (emails.size() == 0) return 0;
        if (emails.size() == 1) return 1;

        std::map<string, int> unique;

        for (size_t i = 0; i < emails.size(); i++)
        {
            string email = emails[i];
            string emailIgnored = getIgnoredLettersOfEmail(email);
            //cout << "Original: " << email << endl;
            cout << "Processed: " << emailIgnored << endl;
            unique[emailIgnored] = 1;
        }

        return unique.size();
    }
};

