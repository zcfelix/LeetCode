/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 14th, 2015
 Problem:    Binary Tree Zigzag Level Order Traversal
 Difficulty: Medium
 Source:     https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 Notes:
 Given a binary tree, return the zigzag level order traversal of its nodes' values. 
 (ie, from left to right, then right to left for the next level and alternate between).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its zigzag level order traversal as:
 [
  [3],
  [20,9],
  [15,7]
 ]

 Solution: 1. Like Binary Tree Levelorder Traversal, use queue 
 		   2. Two stacks..
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
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode* root)
	{
		return zigzagLevelOrder2(root);
	}

	vector<vector<int> > zigzagLevelOrder1(TreeNode* root)
	{
		vector<vector<int> > res;
		queue<TreeNode*> q;
		if (!root) return res;
		q.push(root);
		bool is_reverse = false;
		while (!q.empty())
		{
			int size = static_cast<int>(q.size());
			vector<int> level;
			for (int i = 0; i < size; ++i)
			{
				TreeNode* cur = q.front();
				level.push_back(cur->val);
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			if (is_reverse)
			{
				reverse(level.begin(), level.end());
				is_reverse = false;
			}
			else
				is_reverse = true;
			res.push_back(level);
		}
		return res;
	}

	vector<vector<int> > zigzagLevelOrder2(TreeNode* root)
	{
		vector<vector<int> > res;
		if (!root) return res;
		stack<TreeNode*> stk[2];
		bool left2right = true;
		int cur = 1, last = 0;
		stk[last].push(root);
		vector<int> level;
		while (!stk[last].empty())
		{
			TreeNode* node = stk[last].top();
			stk[last].pop();
			if (node)
			{
				level.push_back(node->val);
				if (left2right)
				{
					stk[cur].push(node->left);
					stk[cur].push(node->right);
				}
				else
				{
					stk[cur].push(node->right);
					stk[cur].push(node->left);
				}
			}
			if (stk[last].empty())
			{
				if (!level.empty())
					res.push_back(level);
				level.clear();
				swap(cur, last);
				left2right = !left2right;
			}
		}
		return res;
	}
};

















