/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 9th, 2015
 Problem:    Best Time to Buy and Sell Stock III
 Difficulty: Hard
 Source:     https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). 
 Solution: Dp. 
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int size = static_cast<int>(prices.size());
		if (size <= 1) return 0;

		vector<int> profit(size);
		int buy = 0;
		buy = prices[0];
		profit[0] = 0;
		for (int i = 1; i < size; ++i)
		{
			profit[i] = max(profit[i - 1], prices[i] - buy);
			buy = min(buy, prices[i]);
		}

		int sell = prices[size - 1];
		int best = 0;
		for (int i = size - 2; i >= 0; i--)
		{
			best = max(best, sell - prices[i] + profit[i]);
			sell = max(sell, prices[i]);
		}

		return best;
	}
};