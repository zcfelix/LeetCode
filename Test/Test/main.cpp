#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../../FlattenBinaryTreetoLinkedList.h"
using namespace std;

int main()
{
    Solution s;
    TreeNode one(1), two(2), three(3), four(4), five(5), six(6), seven(7), eight(8), nine(9), ten(10), eleven(11);
    one.left = &two;
    one.right = &nine;
    two.left = &three;
    two.right = &six;
    three.left = &four;
    three.right = &five;
    six.left = &seven;
    six.right = &eight;
    nine.left = &ten;
    nine.right = &eleven;
    
    s.flatten(&one);
    TreeNode *cur = &one;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->right;
    }
    return 0;
}


