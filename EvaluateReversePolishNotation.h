/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 17th, 2015
 Problem:    Evaluate Reverse Polish Notation
 Difficulty: Medium
 Source:     https://leetcode.com/problems/evaluate-reverse-polish-notation/
 Notes:
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 
 Sulution: Two stacks...
 */

#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> numbers;
		stack<char> operators;

		for (auto i : tokens)
		{
			if (isOp(i))
				operators.push(i[0]);
			else
				numbers.push(stoi(i));
			if (numbers.size() >= 2 && operators.size() > 0)
			{
                int top1 = numbers.top();
				numbers.pop();
                int top2 = numbers.top();
				numbers.pop();
				char op = operators.top();
				operators.pop();
				int ret = calc(top1, top2, op);
				numbers.push(ret);
			}
		}
		return numbers.top();
	}

private:
	bool isOp(const string& s)
	{
		if (s == "+" || s == "-" || s == "*" || s == "/")
			return true;
		else
			return false;
	}

	int calc(int num1, int num2, char op)
	{
		switch(op)
		{
		case '+':
			return num1 + num2;
		case '-':
			return num2 - num1;
		case '*':
			return num1 * num2;
		case '/':
			return num2 / num1;
		}
        return 0;
	}
};



class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> stk;
		for (auto t : tokens)
		{
			if (t.size() > 1 || isdigit(s[0])) stk.push(stoi(t));
			else
			{
				int x2 = stk.top(); stk.pop();
				int x1 = stk.top(); stk.pop();
				switch(s[0])
				{
					case '+': x1 += x2; break;
					case '-': x1 -= x2; break;
					case '*': x1 *= x2; break;
					case '/': x1 /= x2; break; 
				}
				stk.push(x1);
			}
		}
		return stk.top();
	}
};



