/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 11th, 2015
 Problem:    Convert Sorted Array to Binary Search Tree
 Difficulty: Medium
 Source:     https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 Notes:
 Given an array where elements are sorted in ascending order, 
 convert it to a height balanced BST.

 Solution: Recursion.. 
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

#include <vector>
using namespace std;

class Solution
{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.empty()) return NULL;
		TreeNode *ret = helper(nums, 0, nums.size() - 1);
		return ret;
	}

	TreeNode* helper(vector<int>& nums, int start, int end)
	{
		int mid = start + (end - start) / 2;
		if (start > mid || end < mid) return NULL;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = helper(nums, start, mid - 1);
		root->right = helper(nums, mid + 1, end);
		return root;
	}
};
