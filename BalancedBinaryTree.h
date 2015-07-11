/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 6th, 2015
 Problem:    Balanced Binary Tree
 Difficulty: Easy
 Source:     https://leetcode.com/problems/balanced-binary-tree/
 Notes:
 Given an array of strings, return all groups of strings that are anagrams.
 Note: 
 All inputs will be in lower-case.
 Solution: get max left sub tree's height and max right sub tree's height recurrsively
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
	bool isBalanced(TreeNode* root)
	{
		if (root == NULL) 
			return true;
		int lh, rh;
		lh = height(root->left);
		rh = height(root->right);
		if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
			return true;
		return false;
	}
private:
	int height(struct TreeNode* node)
	{
		if (node == NULL) return 0;
		int lh = height(node->left);
		int rh = height(node->right);
		return lh > rh ? lh + 1 : rh + 1;
	}
};