/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 15th, 2015
 Problem:    Climbing Stairs
 Difficulty: Easy
 Source:     https://leetcode.com/problems/climbing-stairs/
 Notes:
 You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Sulution: Climb one step from last stair or climb 2 steps from the last last stair.、
           Fibonacci Sequence
 */

#include <vector>
using namespace std;

class Solution
{
public:

int climbStairs(int n)
{
	return climbStairs2(n);
}

int climbStairs1(int n)
{
	vector<int> ways{1, 1};
	while (n > ways.size() - 1)
	{
		ways.push_back(ways[ways.size() - 1] + ways[ways.size() - 2]);
	}
	return ways[n];
}

int climbStairs2(int n)
{
	int a = 1, b = 1;
	for (int i = 1; i < n; ++i)
	{
		b = b + a;
		a = b - a;
	}
	return b;
}
};

