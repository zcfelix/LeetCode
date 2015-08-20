/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 14th, 2015
 Problem:    Excel Sheet Column Number 
 Difficulty: Easy
 Source:     https://leetcode.com/problems/excel-sheet-column-number/
 Notes:
 Related to question Excel Sheet Column Title
 Given a column title as appear in an Excel sheet, return its corresponding column number.

 For example:
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28 

 Solution: Iter from s.end() to s.begin() and record current weight... 
 */

using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int ret = 0;
		int cur_wight = 1;
		for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
		{
			ret += cur_wight * (*iter - 'A' + 1);
			cur_wight *= 26;
		}
		return ret;
	}
};