/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 11th, 2015
 Problem:    Contains Duplicate II 
 Difficulty: Easy 
 Source:     https://leetcode.com/problems/contains-duplicate-ii/
 Notes:
 Given an array of integers and an integer k, find out whether there 
 are two distinct indices i and j in the array such that nums[i] = nums[j] 
 and the difference between i and j is at most k.

 Solution: Hash or set with sliding window... 
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_map<int, int> records;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (records.find(nums[i]) != records.end())
			{
				if (i - records[nums[i]] <= k)
					return true;
				else
					records[nums[i]] = i;
			}
			else
				records[nums[i]] = i;
		}
		return false;
	}
};


class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_set<int> apperaredNum;
		int start = 0, end = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (apperaredNum.find(nums[i]) == apperaredNum.end())
			{
				apperaredNum.insert(nums[i]);
				++end;
			}
			else
				return true;
			if (end - start > k)
			{
				apperaredNum.erase(nums[start]);
				++start;
			}
		}
		return false;
	}
};

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		unordered_set<int> records;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > k) records.erase(nums[i - k - 1]);
			if (records.find(nums[i]) != records.end())
				return true;
			else
				records.insert(nums[i]);
		}
		return false;
	}
};


