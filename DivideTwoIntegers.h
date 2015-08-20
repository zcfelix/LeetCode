/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 14th, 2015
 Problem:    Divide Two Integers
 Difficulty: Medium
 Source:     https://leetcode.com/problems/divide-two-integers/
 Notes:
 Divide two integers without using multiplication, division and mod operator.
 If it is overflow, return MAX_INT.

 Solution: Use long long to avoid overflowing...
 */

using namespace std;

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
        long long a = static_cast<long long>(dividend);
        long long b = static_cast<long long>(divisor);
	    
	    if (b == 0) return a > 0 ? INT_MAX : INT_MIN;
	    if (a == 0) return 0;
	    if (a == INT_MIN && divisor == -1) return INT_MAX;
        
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
		bool isNegative = (dividend < 0) ^ (divisor < 0);
		int result = 0;
		while (a >= b)
		{
			int shift = 0;
			while (a >= (b << shift))
				++shift;
			a -= b << (shift - 1);
			result += 1 << (shift - 1);	
		}
		return isNegative ? -result : result;
	}
};
