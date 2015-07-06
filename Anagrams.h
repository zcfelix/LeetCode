/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 6th, 2015
 Problem:    Anagrams
 Difficulty: Medium
 Source:     https://leetcode.com/problems/anagrams/
 Notes:
 Given an array of strings, return all groups of strings that are anagrams.
 Note: 
 All inputs will be in lower-case.
 Solution: let the sorted string to be map key and see whether it is anagrams
 */

#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	vector<string> anagrams(vector<string>& strs)
	{
		map<string, vector<int> >anagrams;
		for (size_t i = 0; i < strs.size(); ++i)
		{
			string key = strs[i];
			sort(key.begin(), key.end());
			anagrams[key].push_back(i);
		}
		vector<string> ret;
		for(auto pair : anagrams)
		{
			if (pair.second.size() > 1)
			{
				for (auto index : pair.second)
				{
					ret.push_back(strs[index]);
				}
			}
		}
        return ret;
	}
};