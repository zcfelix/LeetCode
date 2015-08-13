/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 13th, 2015
 Problem:    Course Schedule II 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/course-schedule-ii/
 Notes:
 There are a total of n courses you have to take, labeled from 0 to n - 1.
 Some courses may have prerequisites, for example to take course 0 you have to 
 first take course 1, which is expressed as a pair: [0,1]
 Given the total number of courses and a list of prerequisite pairs, is it possible 
 for you to finish all courses?

 For example:

 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
 So the correct course order is [0,1]

 4, [[1,0],[2,0],[3,1],[3,2]]
 There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
 Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

 Note:
 The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
 Read more about how a graph is represented.

 Solution: 1) Topological sort    http://www.cnblogs.com/easonliu/p/4483437.html
           2) http://blog.csdn.net/kangrydotnet/article/details/45770525

 */

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites)
	{
		vector<int> res;
		vector<vector<int> > graph(numCourses, vector<int>(0));
		vector<int> inDegree(numCourses, 0);
		for (auto i : prerequisites)
		{
			graph[i.second].push_back(i.first);
			++inDegree[i.first];
		}
		queue<int> q;
		for (int i = 0; i < numCourses; ++i)
			if (inDegree[i] == 0) q.push(i);

		while (!q.empty())
		{
			int cur = q.front();
			res.push_back(cur);
			q.pop();
			for (auto v : graph[cur])
			{
				--inDegree[v];
				if (inDegree[v] == 0) q.push(v);
			}
		}
		if (res.size() != numCourses) res.clear();
		return res; 
	}
};







