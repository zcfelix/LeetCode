/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 15th, 2015
 Problem:    Clone Graph
 Difficulty: Medium
 Source:     https://leetcode.com/problems/clone-graph/
 Notes:
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 OJ's undirected graph serialization:
 Nodes are labeled uniquely.
 We use # as a separator for each node, and , as a separator for node label and each neighbor of the node. 
 As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 1) First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 2) Second node is labeled as 1. Connect node 1 to node 2.
 3) Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/

 Sulution: 1. BFS
 		   2. DFS
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		return cloneGraph1(node);
	}

	// BFS
	UndirectedGraphNode *cloneGraph1(UndirectedGraphNode *node)
	{
		if (node == nullptr) return nullptr;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nn_map;
		nn_map[node] = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> q;
		q.push(node);
		while (!q.empty())
		{
			UndirectedGraphNode *tmp = q.front();
			q.pop();
			for (int i = 0; i < tmp->neighbors.size(); ++i)
			{
				UndirectedGraphNode* neighbor = tmp->neighbors[i];
				if (nn_map.find(neighbor) == nn_map.end())
				{
					UndirectedGraphNode* new_node = new UndirectedGraphNode(neighbor->label);
					nn_map[neighbor] = new_node;
					q.push(neighbor);
				}
				nn_map[tmp]->neighbors.push_back(nn_map[neighbor]);
			}
		}
		return nn_map[node];
	}

	// DFS
	UndirectedGraphNode *cloneGraph2(UndirectedGraphNode* node)
	{
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nn_map;
		return cloneGraphRecursively(node, nn_map);
	}

private:
	UndirectedGraphNode *cloneGraphRecursively(UndirectedGraphNode* node, 
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nn_map)
	{
		if (!node) return NULL;
		if (nn_map.find(node) != nn_map.end())
			return nn_map[node];
		UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
		nn_map[node] = new_node;
		for (int i = 0; i < node->neighbors.size(); ++i)
			new_node->neighbors.push_back(cloneGraphRecursively(node->neighbors[i], nn_map));
		return new_node;
	}
};











