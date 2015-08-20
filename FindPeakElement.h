/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 20th, 2015
 Problem:    Find Minimum in Rotated Sorted Array
 Difficulty: Hard
 Source:     https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Notes:
 A peak element is an element that is greater than its neighbors.
 Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 You may imagine that num[-1] = num[n] = -∞.

 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

 Note:
 Your solution should be in logarithmic complexity.

 Solution: Reference: http://siddontang.gitbooks.io/leetcode-solution/content/array/find_peak_element.html 
 */

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		if (nums.size() == 1) return 0;
		int start = 0, end = nums.size() - 1;
		int mid = 0;
		while (start <= end)
		{
			mid = start + (end - start) / 2;
			if ( (mid == 0 || nums[mid] > nums[mid - 1]) &&
				 (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1]) )
				return mid;
			else if (mid > 0 && nums[mid - 1] > nums[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		return mid;
	}
};

