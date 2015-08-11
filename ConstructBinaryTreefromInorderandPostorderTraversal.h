/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 6th, 2015
 Problem:    Construct Binary Tree from Inorder and Postorder Traversal 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 Notes:
 Given inorder and postorder traversal of a tree, construct the binary tree.

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

#include <unordered_map>
#include <vector>
using namespace std;

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (postorder.size() == 0) return NULL;
        return helper(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ist, int ied, int ped)
    {
    	if (ist > ied) return NULL;
    	TreeNode* res = new TreeNode(postorder[ped]);
    	int mid;
    	for (int i = ist; i <= ied; ++i)
    	{
    		if (inorder[i] == res->val)
    		{
    			mid = i;
    			break;
    		}
    	}
    	res->right = helper(inorder, postorder, mid + 1, ied, ped - 1);
    	res->left = helper(inorder, postorder, ist, mid - 1, ped - 1 - ied + mid);
    	return res;
    }
};

// Use Hash map to record index.
class Solution
{
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if (postorder.size() == 0) return NULL;
		unordered_map<int, int> index_record;
		for (int i = 0; i < inorder.size(); ++i)
			index_record[inorder[i]] = i;
		return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, index_record);
	}

private:
	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inL, int inR,
		int postL, int postR, unordered_map<int, int>& index_record)
	{
		if (inL > inR || postL > postR) return NULL;
		TreeNode *root = new TreeNode(postorder[postR]);
		int index = index_record[root->val];
		root->left = helper(inorder, postorder, inL, index - 1, postL, postL + index - inL - 1, index_record);
		root->right = helper(inorder, postorder, index + 1, inR, postR - inR + index, postR - 1, index_record);
		return root;
	}
};
