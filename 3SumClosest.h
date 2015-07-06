/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 6th, 2015
 Update:     Jyl 6th, 2015
 Problem:    3Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_15
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)
 Solution: Simplify '3sum' to '2sum' O(n^2). http://en.wikipedia.org/wiki/3SUM
 Summary of K Sum: http://tech-wonderland.net/blog/summary-of-ksum-problems.html
*/

#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{

		int res = 0, min_offset = INT_MAX;
		int len = static_cast<int>(nums.size());
		if (len < 3) return res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < len; ++i)
		{
			int target_2 = target - nums[i];
			int start = i + 1; 
			int end = len - 1;
			while (start < end)
			{
				int two_sum = nums[start] + nums[end];
				if (two_sum == target_2)
					return target;
				else if (two_sum < target_2)
					++start;
				else
					--end;

				int offset = target_2 - two_sum;
				offset = offset > 0 ? offset : -offset;
				if (offset < min_offset)
				{
					min_offset = offset;
					res = nums[i] + two_sum;
				}
			}
		}
		return res;
	}
};