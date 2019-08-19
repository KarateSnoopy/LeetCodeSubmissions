// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if( root == nullptr )
        {
            return 0;
        }

        int maxDepthOnLeft = maxDepth(root->left);
        int maxDepthOnRight = maxDepth(root->right);
        if( maxDepthOnLeft < maxDepthOnRight )
        {
            return maxDepthOnRight + 1;
        }
        else
        {
            return maxDepthOnLeft + 1;
        }
    }
};

bool VerifyTreeResults1()
{
    Solution s;
    TreeNode* head = new TreeNode(3); 
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    int maxDepth = s.maxDepth(head);
    
    return true;
}

void TestTree1()
{
    bool failed = false;
    if (!VerifyTreeResults1()) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



