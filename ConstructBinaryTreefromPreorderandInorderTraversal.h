/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 10th, 2015
 Problem:    Construct Binary Tree from Preorder and Inorder Traversal 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 Notes:
 Given preorder and inorder traversal of a tree, construct the binary tree.

 Note:
 You may assume that duplicates do not exist in the tree.

 Solution: Recursion 
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
#include <unordered_map>
using namespace std;

class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0) return NULL;
		return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

private:
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preL, int preR,
		int inL, int inR)
	{
		if (preL > preR || inL > inR) return NULL;
		TreeNode* root = new TreeNode(preorder[preL]);
		int mid;
		for (int i = 0; i < inorder.size(); ++i)
		{
			if (inorder[i] == root->val)
			{
				mid = i; 
				break;
			}
		}
		root->left = helper(preorder, inorder, preL + 1, preL + mid - inL, inL, mid - 1);
		root->right = helper(preorder, inorder, preL + mid - inL + 1, preR, mid + 1, inR);
		return root;
	}
};

// Use hash to record index
class Solution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.size() == 0) return NULL;
		unordered_map<int, int> index_record;
		for (int i = 0; i < inorder.size(); ++i)
			index_record[inorder[i]] = i;
		
		return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, index_record);
	}

private:
	TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preL, int preR,
		int inL, int inR, unordered_map<int, int>& index_record)
	{
		if (preL > preR || inL > inR) return NULL;
		TreeNode* root = new TreeNode(preorder[preL]);
		int mid = index_record[root->val];
		root->left = helper(preorder, inorder, preL + 1, preL + mid - inL, inL, mid - 1, index_record);
		root->right = helper(preorder, inorder, preL + mid - inL + 1, preR, mid + 1, inR, index_record);
		return root;
	}
};





