/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 14th, 2015
 Problem:    Binary Tree Right Side View
 Difficulty: Medium
 Source:     https://leetcode.com/problems/binary-tree-right-side-view/
 Notes:
 Given a binary tree, imagine yourself standing on the right side of it, 
 return the values of the nodes you can see ordered from top to bottom.
 For example:
 Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 You should return [1, 3, 4].

 Solution: 1. Like Binary Tree Levelorder Traversal, each right side value is 
 		      the last value of level traversal.... 
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
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		return rightSideView2(root);
	}

	vector<int> rightSideView1(TreeNode* root)
	{
		vector<int> res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int size = static_cast<int>(q.size());
			for (int i = size; i > 0; --i)
			{
				TreeNode* cur = q.front();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
				q.pop();
				if (i == 1)
					res.push_back(cur->val);
			}
		}
		return res;
	}

	vector<int> rightSideView2(TreeNode* root)
	{
		vector<int> res;
		unordered_map<int, int> depth_2_value;
		dfs(root, 1, depth_2_value);
		int depth = 1;
		while (depth_2_value.find(depth) != depth_2_value.end())
			res.push_back(depth_2_value[depth++]);
		return res;
	}

private:
	void dfs(TreeNode* node, int depth, unordered_map<int, int>& depth_2_value)
	{
		if (!node) return;
		depth_2_value[depth] = node->val;
		dfs(node->left, depth + 1, depth_2_value);
		dfs(node->right, depth + 1, depth_2_value);
	}
};


















