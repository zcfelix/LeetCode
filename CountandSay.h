/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 12th, 2015
 Problem:    Count and Say 
 Difficulty: Easy
 Source:     https://leetcode.com/problems/count-and-say/
 Notes:
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: 
 he sequence of integers will be represented as a string.

 Solution: Scan and iteration, using stringstream

 */

using namespace std;

#include <stringstream>
class Solution
{
public:
	string countAndSay(int n)
	{
		string res = "1";
		if (n == 1) return res;
		for (int i = 2; i <= n; ++i)
		{
			stringstream ss;
			for (int j = 0; j < res.size(); ++j)
			{
				int k = j + 1;
				while (k < res.size() && res[k] == res[j])
					++k;
				ss << (k - j) << res[j];
				j = k - 1;
			}
			ss >> res;
		}
		return res;
	}
};