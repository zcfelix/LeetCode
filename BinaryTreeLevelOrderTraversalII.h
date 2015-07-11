/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 11th, 2015
 Problem:    Best Tree Level Order Traversal II
 Difficulty: Easy
 Source:     https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 Notes:
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 (ie, from left to right, level by level from leaf to root).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > levelOrderBottom(TreeNode* root)
	{
		return levelOrderBottom1(root);
	}

	vector<vector<int> > levelOrderBottom1(TreeNode* root)
	{
		vector<vector<int> > res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = static_cast<int>(q.size());
			vector<int> level;
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
		return vector<vector<int> >(res.rbegin(), res.rend());
	}

	vector<vector<int> > levelOrderBottom2(TreeNode* root)
	{
		vector<vector<int> > res;
		levelOrderBottomRecursively(root, 0, res);
		reverse(res.begin(), res.end());
		return res;
	}

	void levelOrderBottomRecursively(TreeNode* node, int level, vector<vector<int> >& res)
	{
		if (node == NULL) return;
		if (res.size() <= level) res.push_back(vector<int>());
		res[level].push_back(node->val);
		levelOrderBottomRecursively(node->left, level + 1, res);
		levelOrderBottomRecursively(node->right, level + 1, res);
	}
};





