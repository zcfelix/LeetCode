/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 20th, 2015
 Problem:    Flatten Binary Tree to Linked List 
 Difficulty: Hard
 Source:     https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 Notes:
 Given a binary tree, flatten it to a linked list in-place.
 For example,
 Given

         1
        / \
       2   5
      / \   \
     3   4   6

 The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

 Solution: 
*/


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution
{
public:
	void flatten(TreeNode* root)
	{
		if (root == nullptr) return;
		if (root->left != nullptr)
		{
			TreeNode *tmp = root->right;
		    root->right = root->left;
			root->left = nullptr;
			TreeNode* cur = root;
			while(cur->right != nullptr) cur = cur->right;
			cur->right = tmp;
		}
		flatten(root->right);
	}
};









