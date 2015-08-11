/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 11th, 2015
 Problem:    Container With Most Water  
 Difficulty: Medium
 Source:     https://leetcode.com/problems/container-with-most-water/
 Notes:
 Given n non-negative integers a1, a2, ..., an, where each represents a point 
 at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
 of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
 forms a container, such that the container contains the most water.

 Note: You may not slant the container.

 Solution:  Two pointer, from side to center...
*/

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int start = 0;
		int end = height.size() - 1;
		int maxV = INT_MIN;
		while (start < end)
		{
			int contain = min(height[end], height[start]) * (end - start);
			maxV = max(maxV, contain);
			if (height[start] <= height[end])
				++start;
			else
				--end;
		}
		return maxV;
	}
};