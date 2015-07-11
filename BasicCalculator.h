/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 8th, 2015
 Problem:    Basic Calculator
 Difficulty: Medium
 Source:     https://leetcode.com/problems/basic-calculator/ 
 Notes:
 Implement a basic calculator to evaluate a simple expression string.
 The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 You may assume that the given expression is always valid.
 Some examples:
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23
 Note: 
 Do not use the eval built-in library function.
 Solution: Remove '()' and change '-' to '+' by stack and add all numbers.  
 */

#include <stack>
using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		stack<int> op_stack;
		op_stack.push(1);
		op_stack.push(1);
		int res = 0;
		for (size_t i = 0; i < s.length(); ++i)
		{
			char c = s.at(i);
			if (isdigit(c))
			{
				int num = c - '0';
				size_t j = i + 1;
				while (j < s.length() && isdigit(s.at(j)))
				{
					num = 10 * num + static_cast<int>(s.at(j) - '0');
					++j;
				}
				res += op_stack.top() * num;
				op_stack.pop();
				i = j - 1;
			}
			else if (c == '+' || c == '(')
				op_stack.push(op_stack.top());
			else if (c == '-')
				op_stack.push(-1 * op_stack.top());
			else if (c == ')')
				op_stack.pop();			
		}
		return res;
	}
};