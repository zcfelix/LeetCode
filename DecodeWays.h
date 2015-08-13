/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 13th, 2015
 Problem:    Decode Ways
 Difficulty: Medium
 Source:     https://leetcode.com/problems/decode-ways/
 Notes:
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.

 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 The number of ways decoding "12" is 2.

 Solution: DP
 		   Count[i] = Count[i - 1] if S[i - 1] is a valid char
 		         or = Count[i - 1] + Count[i - 2] if S[i - 1] and S[i -2] together is still a valid char
 */

using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		if (s.empty() || s[0] == '0') return 0;
		int *p = new int[s.length() + 1]{0};
		p[0] = 1;
		p[1] = s[0] != '0' ? 1 : 0;
		for (int i = 2; i <= s.length(); ++i)
		{
			if (s[i - 1] != '0') p[i] = p[i - 1];
			int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
			if (twoDigits >= 10 && twoDigits <= 26)
				p[i] += p[i - 2];
		}
		int ret = p[s.length()];
		delete [] p;
		return ret;
	}
};

class Solution
{
public:
	int numDecodings(string s)
	{
		if (s.empty() || s[0] == '0') return 0;
		int len = s.length();
		int f0 = 1, f1 = 1;
		for (int i = 1; i < len; ++i)
		{
			if (s[i] == '0') f1 = 0;
			int num = s[i] - '0' + (s[i - 1] - '0') * 10;
			if (num < 10 || num > 26) f0 = 0;
			int tmp = f1;
			f1 = f0 + f1;
			f0 = tmp;
		}
		return f1;
	}
};



