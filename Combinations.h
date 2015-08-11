/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 6th, 2015
 Problem:    Combination Sum III
 Difficulty: Medium
 Source:     https://leetcode.com/problems/combination-sum-iii/
 Notes:
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 For example,
 If n = 4 and k = 2, a solution is:
 [
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
 ]

 Solution: DFS 
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int> > combine(int n, int k)
	{
		vector<vector<int> > res;
		vector<int> path;
		if (n < k) return res;
		DFS(n, k, 1, path, res);
        return res;
	}

private:
	void DFS(int n, int k, int level, vector<int>& path, vector<vector<int> >& res)
	{
		if (path.size() == k)
		{
			res.push_back(path);
			return;
		}
		for (int i = level; i <= n; ++i)
		{
			path.push_back(i);
			DFS(n, k, i + 1, path, res);
			path.pop_back();
		}
	}
};





