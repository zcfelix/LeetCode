/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 6th, 2015
 Problem:    3Sum Closest
 Difficulty: Medium
 Source:     https://leetcode.com/problems/3sum-closest/
 Notes:
 Given an array S of n integers, find three integers in S such that the sum is closest to 
 a given number, target. Return the sum of the three integers. 
 You may assume that each input would have exactly one solution.
 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 Solution: Similar to 3Sum, taking O(n^2) time complexity.
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