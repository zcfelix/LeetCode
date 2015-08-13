/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Aug 13th, 2015
 Problem:    Different Ways to Add Parentheses
 Difficulty: Medium
 Source:     https://leetcode.com/problems/different-ways-to-add-parentheses/
 Notes:
 Given a string of numbers and operators, return all possible results from computing all 
 the different possible ways to group numbers and operators. The valid operators are +, - and *.

 Example 1
 Input: "2-1-1".

 ((2-1)-1) = 0
 (2-(1-1)) = 2
 Output: [0, 2]

 Example 2
 Input: "2*3-4*5"

 (2*(3-(4*5))) = -34
 ((2*3)-(4*5)) = -14
 ((2*(3-4))*5) = -10
 (2*((3-4)*5)) = -10
 (((2*3)-4)*5) = 10
 Output: [-34, -14, -10, -10, 10]

 Solution: 
 */

#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> diffWaysToCompute(string input)
	{
		
	}
};



