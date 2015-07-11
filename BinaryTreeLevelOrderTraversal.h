/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 11th, 2015
 Problem:    Best Tree Level Order Traversal
 Difficulty: Easy
 Source:     https://leetcode.com/problems/binary-tree-level-order-traversal/
 Notes:
 Given a binary tree, return the level order traversal of its nodes' values. 
 (ie, from left to right, level by level).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its level order traversal as:
 [
  [3],
  [9,20],
  [15,7]
 ]

 Solution: 1. queque
 		   2. DFS 
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

#include <queue>
using namespace std;

class Solution
{
public:
	vector<vector<int> > levelOrder(TreeNode* root)
	{
		return levelOrder1(root);
	}

	vector<vector<int> > levelOrder1(TreeNode* root)
	{
		vector<vector<int> > res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> level;
			int size = static_cast<int>(q.size());
			for (int i = 0; i < size; ++i)
			{
				TreeNode* cur = q.front();
				q.pop();
				level.push_back(cur->val);
				if (cur->left != NULL) q.push(cur->left);
				if (cur->right != NULL) q.push(cur->right);
			}
			res.push_back(level);
		}
		return res;
	}

	vector<vector<int> > levelOrder2(TreeNode* root)
	{
		vector<vector<int> > res;
		levelOrderRecursively(root, 0, res);
		return res;
	}

	void levelOrderRecursively(TreeNode *node, int level, vector<vector<int> > &res)
	{
		if (!node) return;
		if (res.size() <= level) res.push_back(vector<int>());
		res[level].push_back(node->val);
		levelOrderRecursively(node->left, level + 1, res);
		levelOrderRecursively(node->right, level + 1, res);
	}
};








