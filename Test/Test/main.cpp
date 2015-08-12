#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../../CopyListwithRandomPointer.h"
using namespace std;

//void inorderTraversal(TreeNode* root)
//{
//    if (!root) return;
//    inorderTraversal(root->left);
//    cout << root->val << " ";
//    inorderTraversal(root->right);
//}
//
//void preorderTraversal(TreeNode* root)
//{
//    if (!root) return;
//    cout << root->val << " ";
//    preorderTraversal(root->left);
//    preorderTraversal(root->right);
//}

int main(int argc, const char * argv[])
{
    Solution s;
    RandomListNode x(1), y(2), z(3);
    x.next = &y;
    y.next = &z;
    x.random = &z;
    y.random = NULL;
    
    RandomListNode *r = s.copyRandomList(&x);
    RandomListNode *cur = r;
    while (cur)
    {
        cout << cur->label << "->";
        cur = cur->next;
    }
    cout << "NULL\n" << "====================" << endl;
    cur = r;
    while (cur)
    {
        cout << cur->label << "->";
        cur = cur->random;
    }
    cout << "NULL" << endl;
}


