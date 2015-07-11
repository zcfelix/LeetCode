/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 8th, 2015
 Problem:    Basic Calculator
 Difficulty: Medium
 Source:     https://leetcode.com/problems/basic-calculator-ii/ 
 Notes:
 Implement a basic calculator to evaluate a simple expression string.
 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 You may assume that the given expression is always valid.
 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5
 Note: 
 Do not use the eval built-in library function.
 Solution:   
 */

#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		vector<string> rpn = changeToRPN(s);
		stack<int> num_stack;
		stack<char> op_stack;
		for (size_t i = 0; i < rpn.size(); ++i)
		{
			string token =  rpn.at(i);
			char c = token[0];
			if (c == '+' || c == '-' || c == '*' || c == '/')
			{
				if (num_stack.size() >= 2)
				{
					int num1 = num_stack.top();
					num_stack.pop();
					int num2 = num_stack.top();
					num_stack.pop();
					num_stack.push(expressionValue(num2, num1, c));
				}
				else
					op_stack.push(c);
			}
            else
				num_stack.push(stoi(token));
		}
		return num_stack.top();
	}

private:
	vector<string> changeToRPN(string s)
	{
		vector<string> rpn;
		stack<char> op_stack;
		for (size_t i = 0; i != s.length(); ++i)
		{
			char c = s.at(i);
			if (isdigit(c))
			{
				size_t j = i + 1;
				string s_num(1, c);
				while (j < s.length() && isdigit(s.at(j)))
				{
					s_num += s.at(j);
					++j;
				}
				rpn.push_back(s_num);
				i = j - 1;
			}
			else if (c == '(')
				op_stack.push(c);
			else if (c == ')')
			{
				while (!op_stack.empty() && op_stack.top() != '(')
				{
					rpn.push_back(string(1, op_stack.top()));
					op_stack.pop();
				}
				op_stack.pop();
			}
			else if (c == '+' || c == '-' || c == '*' || c == '/')
			{
				if (op_stack.empty())
					op_stack.push(c);
				else
				{
					int ret = comparePriority(op_stack.top(), c);
					if (ret < 0)
						op_stack.push(c);
					else
					{
						while (!op_stack.empty() && comparePriority(op_stack.top(), c) >= 0)
						{
							rpn.push_back(string(1, op_stack.top()));
							op_stack.pop();
						}
						op_stack.push(c);
					}
				}
			}
		}

		while (!op_stack.empty())
		{
			rpn.push_back(string(1, op_stack.top()));
			op_stack.pop();
		}
		return rpn;
	}

	int comparePriority(char first, char second)
	{
		unordered_map<char, int> p_map{
			{'(', 0}, {'+', 1}, {'-', 1},
			{'*', 2}, {'/', 2}, {')', 3}
		};
		return p_map[first] - p_map[second];
	}

	int expressionValue(int num1, int num2, char op)
	{
		switch(op)
		{
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			return num1 / num2; 
		}
		return 0;
	}

};