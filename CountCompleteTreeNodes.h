/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 12th, 2015
 Problem:    Count Complete Tree Nodes
 Difficulty: Medium
 Source:     https://leetcode.com/problems/count-complete-tree-nodes/
 Notes:
 Given a complete binary tree, count the number of nodes.

 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, 
 is completely filled, and all nodes in the last level are as far left as possible. 
 It can have between 1 and 2h nodes inclusive at the last level h.

 Solution: 1) Recursion
 		   2) Use binary search to find the last level's nodes...
 		   Reference: http://bookshadow.com/weblog/2015/06/06/leetcode-count-complete-tree-nodes/
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
	int countNodes(TreeNode* root)
	{
		if (root == NULL) return 0;
		int leftHeight = 0, rightHeight = 0;
		TreeNode *l = root, *r = root;
		while (l) { ++leftHeight; l = l->left; }
		while (r) { ++rightHeight; r = r->right; }
		if (leftHeight == rightHeight) 
			return (1 << leftHeight) - 1;
		else
			return 1 + countNodes(root->left) + countNodes(root->right);
	}
};


class Solution
{
public:
	int countNodes(TreeNode* root)
	{
		if (root == NULL) return 0;
		TreeNode *node = root;
		int depth = 0;
		while (node) { ++depth; node = node->left; }
		int left = 0, right = (1 << (depth - 1)) - 1;
		while (left <= right)
		{
			int mid = left + ((right - left) >> 1);
			if (getNode(root, mid, depth - 1))
				left = mid + 1;
			else
				right = mid - 1;
		}
		return (1 << (depth - 1)) + right;
	}

	TreeNode* getNode(TreeNode* root, int path, int depth)
	{
		while (depth-- && root)
		{
			if (path & (1 << depth))
				root = root->right;
			else
				root = root->left;
		}
		return root;
	}
};




