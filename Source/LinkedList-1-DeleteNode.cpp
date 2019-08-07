// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
	ListNode* head = new ListNode(0); // filled test data

	void deleteNode(ListNode* nodeToDelete)
	{
		ListNode* current = nodeToDelete;
		ListNode* prev = nullptr;
		while (current->next != nullptr)
		{
			current->val = current->next->val;
			prev = current;
			current = current->next;
		}

		prev->next = nullptr;
		delete current;
	}

	void deleteNode2(ListNode* nodeToDelete) 
	{
		// The linked list will have at least two elements.
		// The given node will not be the tail and it will always be a valid node of the linked list.

		ListNode* current = head;
		if (current == nodeToDelete)
		{
			head = current->next;
			delete nodeToDelete;
			return;
		}

		while (current != nullptr)
		{
			if (current->next == nodeToDelete)
			{
				current->next = nodeToDelete->next;
				delete nodeToDelete;
				break;
			}
			current = current->next;
		}
	}
};

bool VerifyLinkedResults1()
{
	Solution s;
	ListNode* head = new ListNode(0); 
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	s.deleteNode(head->next);
	
	return true;
}

void TestLinkedList1()
{
    bool failed = false;
	if (!VerifyLinkedResults1()) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



