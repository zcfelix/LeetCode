/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 14th, 2015
 Problem:    Bitwise AND of Numbers Range 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/bitwise-and-of-numbers-range/
 Notes:
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise 
 AND of all numbers in this range, inclusive.
 
 Sulution: http://www.cnblogs.com/grandyang/p/4431646.html
 */

using namespace std;

class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		return rangeBitwiseAnd1(m, n);
	}

	int rangeBitwiseAnd1(int m, int n)
	{
		int d = INT_MAX;
		while ((m & d) != (n & d))
			d <<= 1;
		return m & d;
	}

	int rangeBitwiseAnd2(int m, int n)
	{
		int i = 0;
		while (m != n)
		{
			m >>= 1;
			n >>= 1;
			++i;
		}
		return m << i;
	}
};

