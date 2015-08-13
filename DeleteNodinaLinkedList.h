/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 13th, 2015
 Problem:    Delete Node in a Linked List
 Difficulty: Easy
 Source:     https://leetcode.com/problems/delete-node-in-a-linked-list/
 Notes:
 Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
 the linked list should become 1 -> 2 -> 4 after calling your function.

 Solution: Change the value to the next node's value, and move...
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// May cause memory leak!!!!
class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		if (node == NULL) return;
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

class Solution
{
public:
	void deleteNode(ListNode* node)
	{
		ListNode* pre = node;
		while (node->next != NULL)
		{
			node->val = node->next->val;
			pre = node;
			node = node->next;
		}
		delete(node);
		pre->next = NULL;
	}
};