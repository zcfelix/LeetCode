/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 14th, 2015
 Problem:    Excel Sheet Column Title 
 Difficulty: Easy
 Source:     https://leetcode.com/problems/excel-sheet-column-title/
 Notes:
 Given a positive integer, return its corresponding column title as appear in an Excel sheet.

 For example:
 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB 

 Solution: Iter from s.end() to s.begin() and record current weight... 
 */

using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		string ret = "";
		while (n)
		{
			ret = (char)((n - 1) % 26 + 'A') + ret;
			n = (n - 1) / 26;
		}
		return ret;
	}
};