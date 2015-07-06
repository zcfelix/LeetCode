/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 6th, 2015
 Problem:    Add Two Numbers
 Difficulty: Easy
 Source:     https://leetcode.com/problems/add-two-numbers/
 Notes:
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Solution: dummy head...
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 class Solution
 {
 public:
 	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
 	{
 		int flag = 0;
 		int digit = 0;
 		ListNode *l = new ListNode(0);
 		ListNode *l_cur = l;
 		ListNode *l1_cur = l1;
 		ListNode *l2_cur = l2;
 		while(l1_cur || l2_cur || flag)
 		{
 			int sum = flag;
 			if(l1_cur)
 			{
 				sum += l1_cur->val;
 				l1_cur = l1_cur->next;
 			}
 			if(l2_cur)
 			{
 				sum += l2_cur->val;
 				l2_cur = l2_cur->next;
 			}
 			flag = sum / 10;
 			sum = sum % 10;
 			ListNode *newNode = new ListNode(sum);
 			l_cur->next = newNode;
 			l_cur = newNode;
 		}
 		return l->next;
 	}
 };
