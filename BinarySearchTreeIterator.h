/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 10th, 2015
 Problem:    Best Search Tree Iterator
 Difficulty: Medium
 Source:     https://leetcode.com/problems/binary-search-tree-iterator/
 Notes:
 Implement an iterator over a binary search tree (BST). 
 Your iterator will be initialized with the root node of a BST.
 Calling next() will return the next smallest number in the BST.
 Note: 
 next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 Solution: Using stack and push all the left children to the stack... 
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
using namespace std;

class BSTIterator
{
private: 
	TreeNode* current;
	stack<TreeNode*> my_stack;

public:
	BSTIterator(TreeNode* root)
	{
		current = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return (current != NULL || !my_stack.empty());
	}

	/** @return the next smallest number */
	int next()
	{
		while (current != NULL)
		{
			my_stack.push(current);
			current = current->left;
		}
		current = my_stack.top();
		my_stack.pop();
		int val = current->val;
		current = current->right;
		return val;
	}
};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */