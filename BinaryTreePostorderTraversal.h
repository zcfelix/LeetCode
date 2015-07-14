/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 13th, 2015
 Problem:    Binary Tree Postorder Traversal
 Difficulty: Hard
 Source:     https://leetcode.com/problems/binary-tree-postorder-traversal/
 Notes:
 Given a binary tree, return the postorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
 Return [3,2,1].
 Note:
 Recursive solution is trivial, could you do it iteratively?

 Solution:  1 Iterative solution, transform preorder traversal
 			2 Iterative solution
 			3 Recursive solution
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
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		return postorderTraversal1(root);
	}

	vector<int> postorderTraversal1(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		if (root == NULL) return res;
		stk.push(root);
		while (!stk.empty())
		{
			TreeNode* cur = stk.top();
			res.push_back(cur->val);
			stk.pop();
			if (cur->left) stk.push(cur->left);
			if (cur->right) stk.push(cur->right);
		}
		reverse(res.begin(), res.end());
		return res;
	}

	vector<int> postorderTraversal2(TreeNode* root)
	{
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode *last = NULL, *cur = root;
		while (cur || !stk.empty())
		{
			if (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			else
			{
				TreeNode *top = stk.top();
				if (top->right && last != top->right)
					cur = top->right;
				else
				{
					res.push_back(top->val);
					stk.pop();
					last = top;
				}
			}
		}
		return res;
	}

	vector<int> postorderTraversal3(TreeNode* root)
	{
		vector<int> res;
		postorderTraversalRecursively(root, res);
		return res;
	}

private:
	void postorderTraversalRecursively(TreeNode* node, vector<int>& res)
	{
		if (node == NULL) return;
		postorderTraversalRecursively(node->left, res);
		postorderTraversalRecursively(node->right, res);
		res.push_back(node->val);
	}
};
















