/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 13th, 2015
 Problem:    Course Schedule 
 Difficulty: Medium
 Source:     https://leetcode.com/problems/course-schedule/
 Notes:
 There are a total of n courses you have to take, labeled from 0 to n - 1.
 Some courses may have prerequisites, for example to take course 0 you have to 
 first take course 1, which is expressed as a pair: [0,1]
 Given the total number of courses and a list of prerequisite pairs, is it possible 
 for you to finish all courses?

 For example:

 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
 So it is possible.

 2, [[1,0],[0,1]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
 and to take course 0 you should also have finished course 1. So it is impossible.

 Note:
 The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
 Read more about how a graph is represented.

 Solution: 1) Toplogical sort http://www.cnblogs.com/easonliu/p/4483437.html
 		   2) DFS http://blog.csdn.net/kangrydotnet/article/details/45560127

 */

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
	{
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
			q.pop();
			for (auto v : graph[cur])
			{
				--inDegree[v];
				if (inDegree[v] == 0) q.push(v);
			}
		}

		for (int i = 0; i < numCourses; ++i)
			if (inDegree[i] != 0) return false;
		return true;
	}
};

class Solution
{
public:
	bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
	{
		vector<vector<int> > graph(numCourses, vector<int>(0));
		for (auto i : prerequisites)
			graph[i.first].push_back(i.second);
		bool visit[numCourses];  
		memset(visit, 0, sizeof(bool) * numCourses);
		bool mark[numCourses];
		memset(mark, 0, sizeof(bool) * numCourses);

		for (int i = 0; i < numCourses; ++i)
			if (hasCircle(graph, visit, mark, i)) return false;
		return true;
	}

private:
	bool hasCircle(vector<vector<int> >& graph, bool visit[], bool mark[],
		int cur)
	{
		if (visit[cur]) return true;
		if (mark[cur]) return false;
		visit[cur] = true;
		for (int i = 0; i < graph[cur].size(); ++i)
			if (hasCircle(graph, visit, mark, graph[cur][i])) return true;

		mark[cur] = true;           // Start from the current node, and the child graph has no circle
		visit[cur] = false;         
		return false;
	}
};







