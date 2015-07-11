/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 11th, 2015
 Problem:    Binary Tree Inorder Traveral
 Difficulty: Medium
 Source:     https://leetcode.com/problems/binary-tree-inorder-traversal/
 Notes:
 Given a binary tree, return the inorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
    1
    \
     2
    /
   3
 return [1, 3, 2].
 Note:
 Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Recursive Solution
 		   2. Iterative Solution
 		   3. Morris Solution
 
 http://www.gocalf.com/blog/traversing-binary-tree.html
 http://noalgo.info/832.html
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

#include <stack>
using namespace std;

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		return inorderTraversal1(root);
	}

	vector<int> inorderTraversal1(TreeNode* root)
	{
		vector<int> res;
		inorderTraversalRecursively(root, res);
		return res;
	}

	vector<int> inorderTraversal2(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode* cur = root;
		while (cur || !stk.empty())
		{
			if (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else if (!stk.empty())
			{
				res.push_back(stk.top()->val);
				cur = stk.top()->right;
				stk.pop();
			}
		}
		return res;
	}

	vector<int> inorderTraversal3(TreeNode* root)
	{
		vector<int> res;
		TreeNode* cur = root;
		while (cur)
		{
			if (cur->left)
			{
				TreeNode* prev = cur->left;
				while (prev->right && prev->right != cur)
					prev = prev->right;

				if (prev->right == cur)
				{
					res.push_back(cur->val);
					cur = cur->right;
					prev->right = NULL;
				}
				else
				{
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
	void inorderTraversalRecursively(TreeNode* node, vector<int>& res)
	{
		if (!node) return;
		inorderTraversalRecursively(node->left, res);
		res.push_back(node->val);
		inorderTraversalRecursively(node->right, res);
	}
};














