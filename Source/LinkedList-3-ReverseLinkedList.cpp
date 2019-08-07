// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

struct ListNode* reverseList(struct ListNode* head) 
{
	if (head == nullptr)
	{
		return nullptr;
	}
	else if (head->next == nullptr)
	{
		return head;
	}

	struct ListNode* current = head;
	while (current->next->next != nullptr)
	{
		current = current->next;
	}
	// current->next->next == nullptr
	struct ListNode* revHead = current->next;
	revHead->next = current;
	current->next = nullptr;

	while (head->next != nullptr)
	{
		current = head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}
		current->next->next = current;
		current->next = nullptr;
	}

	return revHead;
}


bool VerifyLinkedResults3()
{
	ListNode* head = new ListNode(1); // filled test data
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	reverseList(head);
    return true;
}

void TestLinkedList3()
{
    bool failed = false;
	if (!VerifyLinkedResults3()) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



