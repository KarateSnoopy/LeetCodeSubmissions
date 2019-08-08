// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};


struct ListNode* mergeList(
	struct ListNode* l1,  
	struct ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}

	struct ListNode* output = NULL;
	struct ListNode* outTail = NULL;
	if (l1->val == l2->val)
	{
		output = l1;
		outTail = l2;
		l1 = l1->next;
		l2 = l2->next;

		output->next = outTail;
		outTail->next = NULL;
	}
	else if (l1->val < l2->val)
	{
		output = l1;
		outTail = l1;
		l1 = l1->next;
		outTail->next = NULL;
	}
	else
	{
		output = l2;
		outTail = l2;
		l2 = l2->next;
		outTail->next = NULL;
	}

	while (l1 != NULL || l2 != NULL)
	{
		if (l1 == NULL)
		{
			outTail->next = l2;
			break;
		}

		if (l2 == NULL)
		{
			outTail->next = l1;
			break;
		}

		struct ListNode* tempL1 = l1;
		struct ListNode* tempL2 = l2;
		if (l1->val == l2->val)
		{
			l1 = l1->next;
			l2 = l2->next;

			outTail->next = tempL1;
			tempL1->next = tempL2;
			tempL2->next = NULL;
			outTail = tempL2;
		}
		else if (l1->val < l2->val)
		{
			l1 = l1->next;

			outTail->next = tempL1;
			tempL1->next = NULL;
			outTail = tempL1;
		}
		else
		{
			l2 = l2->next; 

			outTail->next = tempL2;
			tempL2->next = NULL;
			outTail = tempL2;
		}
	}

	return output;
}


bool VerifyLinkedResults4()
{
	ListNode* head1 = new ListNode(1); // filled test data
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(4);
	//head1->next->next->next = new ListNode(4);
	//head1->next->next->next->next = new ListNode(5);

	ListNode* head2 = new ListNode(1); // filled test data
	head2->next = new ListNode(3);
	head2->next->next = new ListNode(4);
//	head2->next->next->next = new ListNode(4);
//	head2->next->next->next->next = new ListNode(5);
	ListNode* output = mergeList(head1, head2);
    return true;
}

void TestLinkedList4()
{
    bool failed = false;
	if (!VerifyLinkedResults4()) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}



