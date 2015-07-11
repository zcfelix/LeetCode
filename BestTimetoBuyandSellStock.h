/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 8th, 2015
 Problem:    Best Time to Buy and Sell Stock
 Difficulty: Medium
 Source:     https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
 design an algorithm to find the maximum profit.
 Solution: For every day's price, calculate the max profit with the former prices 
 */


using namespace std;
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() <= 1) return 0;
		int min_price = INT_MAX, max_profit = INT_MIN;
		for (size_t i = 0; i < prices.size(); ++i)
		{
			min_price = min(min_price, prices.at(i));
			max_profit = max(max_profit, prices.at(i) - min_price);
		}
		return max_profit;
	}
};