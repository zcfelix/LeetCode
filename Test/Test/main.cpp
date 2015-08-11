#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../../ContainsDuplicateIII.h"
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
    map<int, int> m{ {2, 100}, {1, 300}, {3, 200} };
    for (auto i : m)
    {
        cout << i.first << ": " << i.second << endl;
    }
    auto iter = m.lower_bound(3);
    cout << "========================" << endl;
    for (; iter != m.end(); ++iter)
        cout << iter->first << ": " << iter->second << endl;
    return 0;
}


