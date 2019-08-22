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


    bool isBstBigger(int parentVal, TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val <= parentVal)
        {
            return false;
        }

        if (isBstBigger(parentVal, root->left) == false)
        {
            return false;
        }

        if (isBstBigger(parentVal, root->right) == false)
        {
            return false;
        }

        return true;
    }
    
    bool isBstSmaller(int parentVal, TreeNode* root)
    {
        if( root == nullptr )
        {
            return true;
        }

        if( root->val >= parentVal )
        {
            return false;
        }

        if( isBstSmaller(parentVal, root->left) == false )
        {
            return false;
        }

        if (isBstSmaller(parentVal, root->right) == false)
        {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) 
    {
        if( root == nullptr )
        {
            return true;
        }

        if( root->left != nullptr )
        {
            if (root->left->val >= root->val)
            {
                return false;
            }
        }

        if (root->right != nullptr)
        {
            if (root->right->val <= root->val)
            {
                return false;
            }
        }

        if( isBstSmaller(root->val, root->left) == false )
        {
            return false;
        }

        if (isBstBigger(root->val, root->right) == false)
        {
            return false;
        }

        if( isValidBST(root->left) == false )
        {
            return false;
        }

        if( isValidBST(root->right) == false )
        {
            return false;
        }

        return true;
    }
};

bool VerifyTreeResults2()
{
    Solution s;
    TreeNode* head = new TreeNode(3); 
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    int maxDepth = s.isValidBST(head);
    
    return true;
}

void TestTree2()
{
    bool failed = false;
    if (!VerifyTreeResults2()) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



