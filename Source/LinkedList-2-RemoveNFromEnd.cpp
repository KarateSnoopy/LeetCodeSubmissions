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
	void removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* scout = head;
		int counter = 0;
		while (scout != nullptr)
		{
			scout = scout->next;
			counter++;
		}

		int nodeToFindIndex = counter - n;
		if (nodeToFindIndex == 0)
		{
			// deleting head
			ListNode* oldhead = head;
			head = head->next;
			delete oldhead;
			return;
		}
		ListNode* current = head;
		counter = 1;
		while (current != nullptr)
		{
			if (counter == nodeToFindIndex)
			{
				ListNode* suicide = current->next;
				current->next = current->next->next;
				delete suicide;
				return;
			}

			counter++;
			current = current->next;
		}
	}
};

bool VerifyLinkedResults2()
{
	ListNode* head = new ListNode(1); // filled test data
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	Solution s;
	s.removeNthFromEnd(head, 5);
    return true;
}

void TestLinkedList2()
{
    bool failed = false;
	if (!VerifyLinkedResults2()) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



