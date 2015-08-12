/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 12th, 2015
 Problem:    Count Complete Tree Nodes
 Difficulty: Count Primes 
 Source:     https://leetcode.com/problems/count-primes/
 Notes:
 Count the number of prime numbers less than a non-negative number, n.

 Solution: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Algorithm_complexity
 		   Time: O(nloglogn)  Space: O(n)
 */


using namespace std;

class Solution
{
public:
	int countPrimes(int n)
	{
		bool *pIsPrime = new bool[n];
		for (int i = 2; i < n; ++i)
			pIsPrime[i] = true;

		for (int i = 2; i * i < n; ++i)
		{
			if (!pIsPrime[i]) continue;
			for (int j = i * i; j < n; j += i)
				pIsPrime[j] = false;
		}

		int count = 0;
		for (int i = 2; i < n; ++i)
			if (pIsPrime[i]) ++count;

		delete [] pIsPrime;
		return count;
	}
};


