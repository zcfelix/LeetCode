/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 8th, 2015
 Problem:    Best Time to Buy and Sell Stock II
 Difficulty: Medium
 Source:     https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions as 
 you like (ie, buy one and sell one share of the stock multiple times). 
 However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 Solution: Find the max price and min price and calculate the profit in all sections. 
 */

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		return maxProfit2(prices);
	}

private:
	int maxProfit1(vector<int>& prices)
	{
		int sum_profit = 0;
		size_t len = prices.size();
		if (len <= 1) return 0;
		const size_t LAST = len - 1;
		size_t i = 0;
		while (i < LAST)
		{
			if (prices[i+ 1] < prices[i])
			{
				++i;
				continue;
			}
			size_t j = i + 1;
			while (j + 1 <= LAST && prices[j + 1] >= prices[j])
				++j;

			int cur_profit = prices[j] - prices[i];
			sum_profit += cur_profit;
			if (j == LAST)
				break;
			else
				i = j;
		}
		return sum_profit;
	}

	int maxProfit2(vector<int>& prices)
	{
		int len = static_cast<int>(prices.size());
		if (len <= 1) return 0;
		int res = 0;
		for (int i = 0; i < len - 1; ++i)
			if (prices[i + 1] - prices[i] > 0)
				res += prices[i + 1] - prices[i];
		return res;
	}
};

