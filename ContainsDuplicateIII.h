/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 11th, 2015
 Problem:    Contains Duplicate III 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/contains-duplicate-iii/
 Notes:
 Given an array of integers, find out whether there are two distinct indices 
 i and j in the array such that the difference between nums[i] and nums[j] is 
 at most t and the difference between i and j is at most k.

 Solution: Use map and its lower_bound 
*/

#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		map<int, int> m;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i - j > k)
				m.erase(nums[j++]);
			auto iter = m.lower_bound(nums[i] - t);
			if (iter != m.end() && abs(iter->first - nums[i]) <= t)
				return true;
			m[nums[i]] = i;
		}
		return false;
	}
};




