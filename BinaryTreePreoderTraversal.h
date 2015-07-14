/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 13th, 2015
 Problem:    Binary Tree Preorder Traversal
 Difficulty: Medium
 Source:     https://leetcode.com/problems/binary-tree-preorder-traversal/
 Notes:
 Given a binary tree, return the preorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
 Return [1,2,3].
 Note:
 Recursive solution is trivial, could you do it iteratively?

 Solution:  1 Stack iterative solution
 			2 Recursive solution
 			3 Morris solution
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
#include <stack>
using namespace std;

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		return preorderTraversal3(root);
	}

	vector<int> preorderTraversal1(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		if (root == NULL) return res;
		TreeNode* cur = root;
		stk.push(cur);
		while (!stk.empty())
		{
			cur = stk.top();
			stk.pop();
			res.push_back(cur->val);
			if (cur->right) stk.push(cur->right);
			if (cur->left) stk.push(cur->left);
		}
		return res;
	}

	vector<int> preorderTraversal2(TreeNode* root)
	{
		vector<int> res;
		preorderTraversalRecursively(root, res);
		return res;
	}

    vector<int> preorderTraversal3(TreeNode *root) 
    {
        vector<int> res;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                    
                if (prev->right == cur)
                {
                    cur = cur->right;
                    prev->right = NULL;
                }
                else
                {
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

private:
	void preorderTraversalRecursively(TreeNode* node, vector<int>& res)
	{
		if (node == NULL) return;
		res.push_back(node->val);
		preorderTraversalRecursively(node->left, res);
		preorderTraversalRecursively(node->right, res);
	}
};









