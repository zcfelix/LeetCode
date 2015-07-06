/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 6th, 2015
 Problem:    Add Binary
 Difficulty: Easy
 Source:     https://leetcode.com/problems/add-binary/
 Notes:
 Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".
 Solution: '1'-'0' = 1.
 */

#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int size_a = static_cast<int>(a.length());
		int size_b = static_cast<int>(b.length());
		int flag = 0;
		string res;
		while (size_a > 0 || size_b > 0 || flag > 0)
		{
			int i_1 = size_a > 0 ? int(a[-1 + size_a--]) - int('0') : 0;
			int i_2 = size_b > 0 ? int(b[-1 + size_b--]) - int('0') : 0;
			int sum = i_1 + i_2 + flag;
			int bit = sum % 2;
			flag = sum / 2;
			res.append(1, char(bit + '0'));
		}
		return string(res.rbegin(), res.rend());
	}
};