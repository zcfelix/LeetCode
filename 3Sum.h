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
 	vector<vector<int> > threeSum(vector<int> &nums)
 	{
 		vector<vector<int> > result;
 		int len = static_cast<int>(nums.size());
 		if (len < 3) return result;
 		sort(nums.begin(), nums.end());

 		for (int i = 0; i < len && nums[i] <= 0; ++i)
 		{
 			int target_2 = 0 - nums[i];
 			int start = i + 1;
 			int end = len - 1;
 			while (start < end)
 			{
 				int two_sum = nums[start] + nums[end];
 				if (two_sum < target_2)
 					++start;
 				else if (two_sum > target_2)
 					--end;
 				else
 				{
 					vector<int> triplet{nums[i], nums[start], nums[end]};
 					result.push_back(triplet);
 					while (start < end && nums[start] == triplet[1])
 						++start;
 					while (start < end && nums[end] == triplet[2])
 						--end;
 				}
 			}
 			while (i + 1 < len && nums[i + 1] == nums[i])
 				++i;
 		}
 		return result;
 	}
};


