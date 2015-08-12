/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 11th, 2015
 Problem:    Convert Sorted List to Binary Search Tree 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 Notes:
 Given a singly linked list where elements are sorted in ascending order, 
 convert it to a height balanced BST.

 Solution: 1) First, copy to vector, than recursion...
 		   2) Use inorder traversal of tree... 

 Problems Reference: 1) http://stackoverflow.com/questions/5789806/meaning-of-and-in-c
 					 2) http://www.cnblogs.com/fengfly/archive/2009/09/24/1573288.html
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		if (head == NULL) return NULL;
		vector<int> nums;
		ListNode* tmp = head;
		while (tmp != NULL)
		{
			nums.push_back(tmp->val);
			tmp = tmp->next;
		}
		TreeNode* ret = helper(nums, 0, nums.size() - 1);
		return ret;
	}

	TreeNode* helper(vector<int>& nums, int start, int end)
	{
		int mid = start + (end - start) / 2;
		if (start > mid || end < mid) return NULL;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = helper(nums, start, mid - 1);
		root->right = helper(nums, mid + 1, end);
		return root;
	}
};

class Solution
{
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		int len = 0;
		ListNode* cur = head;
		while (cur)
		{
			++len;
			cur = cur->next;
		}
		return helper(head, 0, len - 1);
	}

private:
	TreeNode* helper(ListNode*& p, int start, int end)    // ListNode* p， test case will be wrong，why?
	{
		if (start > end) return NULL;
		int mid = start + (end - start) / 2;
		TreeNode *leftChild = helper(p, start, mid - 1);
		TreeNode *root = new TreeNode(p->val);
		root->left = leftChild;
		p = p->next;
		root->right = helper(p, mid + 1, end);
		return root;
	}
};




