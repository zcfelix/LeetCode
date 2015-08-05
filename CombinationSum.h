/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 4th, 2015
 Problem:    Combination Sum
 Difficulty: Medium
 Source:     https://leetcode.com/problems/combination-sum/
 Notes:
 Given a set of candidate numbers (C) and a target number (T), 
 find all unique combinations in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.

 For example, given candidate set 2,3,6,7 and target 7, 
 A solution set is: 
 [7] 
 [2, 2, 3]

 Solution: Sort & Recursion 
*/

#include <vector>
#include <alogrithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int> > result;
		if (candidates.size() == 0) return result;
		vector<int> solution;
		int sum = 0;
		sort(candidates.begin(), candidates.end());
		GetCombination(candidates, sum, 0, target, solution, result);
	}

	void GetCombination(vector<int>& candidates, int& sum, int level, 
		int target, vector<int>& solution, vector<vector<int> >& result)
	{
		if (sum > target) return;
		if (sum == target)
		{
			result.push_back(solution);
			return;
		}
		for (int i = level; i < candidates.size(); ++i)
		{
			sum += candidates[i];
			solution.push_back(candidates[i]);
			GetCombination(candidates, sum, i, target, solution, result);
			solution.pop_back();
			sum -= candidates[i];
		}
	}	
};













