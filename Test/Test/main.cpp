#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "../../EvaluateReversePolishNotation.h"
using namespace std;

int main()
{
    Solution s;
    vector<string> tokens{"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}


