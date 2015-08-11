/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 6th, 2015
 Problem:    Compare Version Numbers
 Difficulty: Easy
 Source:     https://leetcode.com/problems/compare-version-numbers/
 Notes:
 Compare two version numbers version1 and version2.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", 
 it is the fifth second-level revision of the second first-level revision.

 Here is an example of version numbers ordering:

 0.1 < 1.1 < 1.2 < 13.37

 Solution: Split string. 
*/

#include <vector>
using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		vector<string> v1 = split(version1);
		vector<string> v2 = split(version2);
		int len1 = v1.size();
		int len2 = v2.size();
		int len = len1 < len2 ? len1 : len2;
		for (int i = 0; i < len; ++i)
		{
			if (stoi(v1[i]) > stoi(v2[i]))
				return 1;
			else if (stoi(v1[i]) < stoi(v2[i]))
				return -1;
		}
		if (len1 == len2) return 0;
		else if (len1 < len2)
		{
			for (int i = len1; i < len2; ++i)
			{
				if (stoi(v2[i]) != 0) return -1;
			}
			return 0;
		}
		else
		{
			for (int i = len2; i < len1; ++i)
			{
				if (stoi(v1[i]) != 0) return 1; 
			}
			return 0;
		}
	}

private:
	vector<string> split(string version)
	{
		vector<string> res;
		string::size_type pos1, pos2;
		pos2 = version.find('.');
		pos1 = 0;
		while (pos2 != string::npos)
		{
			res.push_back(version.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;
			pos2 = version.find('.', pos1);
		}
		if (pos1 != version.length())
			res.push_back(version.substr(pos1));

		return res;
	}
};