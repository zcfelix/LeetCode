/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 11th, 2015
 Problem:    Contains Duplicate 
 Difficulty: Easy 
 Source:     https://leetcode.com/problems/contains-duplicate/
 Notes:
 Given an array of integers, find if the array contains any duplicates. 
 Your function should return true if any value appears at least twice in the array, 
 and it should return false if every element is distinct.

 Solution: Hash or sort first... 
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_map<int, bool> records;
		for (auto i : nums)
		{
			if (records.find(i) != records.end())
				return true;
			else
				records[i] = true;
		}
		return false;
	}
};

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		return unique(nums.begin(), nums.end()) != nums.end();
	}
};
