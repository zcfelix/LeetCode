/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 19th, 2015
 Problem:    Find Minimum in Rotated Sorted Array
 Difficulty: Medium
 Source:     https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 You may assume no duplicate exists in the array.

 Solution: 1) Time: O(n)
 		   2) Binary Search, Time: O(logn)   
 		      Reference: http://bangbingsyb.blogspot.com/2014/11/leecode-find-minimum-in-rotated-sorted.html 
 */

class Solution
{
public:
	int findMin(vector<int>& nums)
	{
		if (nums.empty()) return 0;
		int min = nums[0];
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] < min) return nums[i];
		return min;
	}
};

class Solution
{
public:
	int findMin(vector<int>& nums)
	{
		int start = 0, end = nums.size() - 1;
		while (start < end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] < nums[end])
				end = mid;
			else
				start = mid + 1;
		}
		return nums[start];
	}
};