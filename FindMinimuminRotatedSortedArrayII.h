/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 20th, 2015
 Problem:    Find Minimum in Rotated Sorted Array
 Difficulty: Hard
 Source:     https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Notes:
 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 The array may contain duplicates.

 Solution: Reference: http://bangbingsyb.blogspot.com/2014/11/leecode-find-minimum-in-rotated-sorted.html  
 */

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
			else if (nums[mid] > nums[end])
				start = mid + 1;
			else
				--end;
		}
		return nums[start];	
	}
};