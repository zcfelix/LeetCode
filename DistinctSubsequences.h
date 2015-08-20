/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 14th, 2015
 Problem:    Distinct Subsequences
 Difficulty: Hard
 Source:     https://leetcode.com/problems/distinct-subsequences/
 Notes:
 Given a string S and a string T, count the number of distinct subsequences of T in S.
 A subsequence of a string is a new string which is formed from the original string by 
 deleting some (can be none) of the characters without disturbing the relative positions 
 of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 Here is an example:
 S = "rabbbit", T = "rabbit"

 Return 3
 
 Sulution: DP. dp[i][j] = dp[i-1][j]  if s[i-1] != t[j-1]
 					 or = dp[i-1][j] + dp[i-1][j-1] if s[i-1] == t[j-1]
 		   reference: http://fisherlei.blogspot.jp/2012/12/leetcode-distinct-subsequences_19.html
 		   			  http://blog.csdn.net/abcbc/article/details/8978146
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int slen = s.length(), tlen = t.length();
		vector<vector<int> > dp(slen  + 1, vector<int>(tlen + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= slen; ++i)
			dp[i][0] = 1;
		for (int j = 1; j <= tlen; ++j)
			dp[0][j] = 0;
		for (int i = 1; i <= slen; ++i)
		{
			for (int j = 1; j <= tlen; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1]) dp[i][j] += dp[i - 1][j - 1];
			}
		}
		return dp[slen][tlen];
	}
};


// 
class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int *match = new int[t.length() + 1];
		if (s.length() < t.length()) return 0;
		match[0] = 1;

		for (int i = 1; i <= t.length(); ++i)
			match[i] = 0;
		for (int i = 1; i <= s.length(); ++i)
		{
			for (int j = t.length(); j >= 1; --j)
			{
				if (s[i - 1] == t[j - 1])
					match[j] += match[j - 1];
			}
		}
		int ret = match[t.length()];
		delete [] match;
		return ret;
	}
};

