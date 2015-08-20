/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 13th, 2015
 Problem:    Different Ways to Add Parentheses
 Difficulty: Medium
 Source:     https://leetcode.com/problems/different-ways-to-add-parentheses/
 Notes:
 Given a string of numbers and operators, return all possible results from computing all 
 the different possible ways to group numbers and operators. The valid operators are +, - and *.

 Example 1
 Input: "2-1-1".

 ((2-1)-1) = 0
 (2-(1-1)) = 2
 Output: [0, 2]

 Example 2
 Input: "2*3-4*5"

 (2*(3-(4*5))) = -34
 ((2*3)-(4*5)) = -14
 ((2*(3-4))*5) = -10
 (2*((3-4)*5)) = -10
 (((2*3)-4)*5) = 10
 Output: [-34, -14, -10, -10, 10]

 Solution: 1) Recursion...
 		   2) DP 
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<int> diffWaysToCompute(string input)
	{
		vector<int> res;
		int len = input.length();
		for (int i = 0; i < len; ++i)
		{
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*')
			{
				vector<int> res1 = diffWaysToCompute(input.substr(0, i));
				vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
				for (auto n1 : res1)
				{
					for (auto n2 : res2)
					{
						if (cur == '+')
							res.push_back(n1 + n2);
						else if (cur == '-')
							res.push_back(n1 - n2);
						else
							res.push_back(n1 * n2);
					}
				}
			}
		}
		// if the input string contains only number 
		if (res.empty())
			res.push_back(stoi(input));
		return res;
	}
};

class Solution
{
public:
	vector<int> diffWaysToCompute(string input)
	{
		unordered_map<string, vector<int>> dpMap;
		return helper(input, dpMap);
	}

private:
	vector<int> helper(string input, unordered_map<string, vector<int> >& dpMap)
	{
		vector<int> res;
		int len = input.length();
		for (int i = 0; i < len; ++i)
		{
			char cur = input[i];
			if (cur == '+' || cur == '-' || cur == '*')
			{
				vector<int> res1, res2;
				string tmp = input.substr(0, i);

				// check if dpMap has the result for tmp
				if (dpMap.find(tmp) != dpMap.end())
					res1 = dpMap[tmp];
				else
					res1 = helper(tmp, dpMap);

				tmp = input.substr(i + 1);
				if (dpMap.find(tmp) != dpMap.end())
					res2 = dpMap[tmp];
				else
					res2 = helper(tmp, dpMap);

				for (auto n1 : res1)
				{
					for (auto n2 : res2)
					{
						if (cur == '+')
							res.push_back(n1 + n2);
						else if (cur == '-')
							res.push_back(n1 - n2);
						else
							res.push_back(n1 * n2);
					}
				}
			}
		}
		// if the input string contains only number
		if (res.empty())
			res.push_back(stoi(input));
		// save to dpMap
		dpMap[input] = res;
		return res;
	}
};







