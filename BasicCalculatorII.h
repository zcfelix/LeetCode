/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 8th, 2015
 Problem:    Basic Calculator II
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
 Solution: The string has no '()', so first calculate '*' and '/', and then calculate '+' and '-'.
 */

using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		int result = 0;
		int cur_res = 0;
		char op = '+';
		for (size_t pos = s.find_first_not_of(' '); 
			pos < s.length(); pos = s.find_first_not_of(' ', pos))
		{
			if (isdigit(s.at(pos)))
			{
				int tmp = s.at(pos) - '0';
				while(++pos < s.length() && isdigit(s.at(pos)))
					tmp = tmp * 10 + static_cast<int>(s.at(pos) - '0');
				switch(op)
				{
				case '+':
					cur_res += tmp;
					break;
				case '-':
					cur_res -= tmp;
					break;
				case '*':
					cur_res *= tmp;
					break;
				case '/':
					cur_res /= tmp;
					break;
				}
			}
			else
			{
				if (s.at(pos) == '+' || s.at(pos) == '-')
				{
					result += cur_res;
					cur_res = 0;
				}
				op = s.at(pos++);
			}
		}
		return result + cur_res;
	}
};






