/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 12th, 2015
 Problem:    Copy List with Random Pointer 
 Difficulty: Hard 
 Source:     https://leetcode.com/problems/copy-list-with-random-pointer/
 Notes:
 A linked list is given such that each node contains an additional random pointer 
 which could point to any node in the list or null.

 Return a deep copy of the list.

 Solution: 1) Hash, key is origin node ptr, value is new node ptr.
 			  Time: O(n), Space: O(n)
		   2) Making connections about old and new list, 
		   	  Reference: http://www.cnblogs.com/lautsie/p/3259724.html
		   	  http://blog.csdn.net/fightforyourdream/article/details/16879561
		   	  Time: O(n), Space: O(1) 
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <unordered_map>
using namespace std;

class Solution
{
public:
	RandomListNode* copyRandomList(RandomListNode *head)
	{
		if (head == NULL) return NULL;
		unordered_map<RandomListNode*, RandomListNode*> records;
		RandomListNode* cur = head;
		while (cur)
		{
			records[cur] = new RandomListNode(cur->label);
			cur = cur->next;
		}

		cur = head;
		while (cur)
		{
			records[cur]->next = records[cur->next];
			records[cur]->random = records[cur->random];
			cur = cur->next;
		}
		return records[head];	
	}
};


class Solution
{
public:
	RandomListNode* copyRandomList(RandomListNode *head)
	{
		if (head == NULL) return NULL;
		RandomListNode *cur = head;

		// Insert new nodes
		while (cur)
		{
			RandomListNode *tmp = new RandomListNode(cur->label);
			tmp->next = cur->next;
			cur->next = tmp;
			cur = tmp->next;
		}

		// Copy random pointer
		cur = head;
		while(cur)
		{
			RandomListNode *tmp = cur->next;
			if (cur->random)
				tmp->random = cur->random->next;
			cur = tmp->next;
		}

		// depart two links
		cur = head;
		RandomListNode *ret = head->next;
		while(cur)
		{
			RandomListNode *tmp = cur->next;
			cur->next = tmp->next;
			if (tmp->next)
				tmp->next = tmp->next->next;
			cur = cur->next;
		}
		return ret;
	}
};












