	/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 20th, 2015
 Problem:    Factorial Trailing Zeroes 
 Difficulty: Easy 
 Source:     https://leetcode.com/problems/factorial-trailing-zeroes/
 Notes:
 Given an integer n, return the number of trailing zeroes in n!.
 Note: Your solution should be in logarithmic time complexity.

 Solution:  Reference: http://www.danielbit.com/blog/puzzle/leetcode/leetcode-factorial-trailing-zeroes
*/

class Solution
{
public:
	int trailingZeros(int n)
	{
		int zeroes = 0;
		while (n / 5 > 0)
		{
			zeroes += n / 5;
			n /= 5;
		}
		return zeros;
	}
};