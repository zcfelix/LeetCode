/*
 Author:     Felix Zhou, zcfelix.zhou@gmail.com
 Date:       Jul 9th, 2015
 Problem:    Best Time to Buy and Sell Stock IV
 Difficulty: Hard
 Source:     https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most k transactions.
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). 
 Solution: Dp.  http://blog.csdn.net/linhuanmars/article/details/23236995  https://gist.github.com/ElninoFong/d08051d98e634991cd93
 */

#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(int k, vector<int>& prices)
	{
		return maxProfit1(k, prices);
	}

	int maxProfit1(int k, vector<int>& prices)
	{
		int len = static_cast<int>(prices.size());
		if (len <= 1) return 0;

		int maxProfit = 0;
		// Simple case where we just need to find the maximum climb in prices among all the pairs
		if (k >= len / 2)
		{
			for (int i = 1; i < len; ++i)
				maxProfit += max(0, prices[i] - prices[i - 1]);
			return maxProfit;
		}

		// Dynamic Programming case where we need to maximize our profit

		// Keeps track of maximum profit so far at each index. On any index 'i' the value is max profit 
		// that we gained by dealing stock that came before 'i'. After any 'm' interations, this array
		// holds max profit on index 'i' if we had only 'i' stock values and 'm' possible deals
		vector<int> maxProfitSoFar(len + 1, 0);

		// calculate the differences between the very current and previous stock price
		int currentProfit = 0;

		// keeps track of our current balance
		int runningProfit = 0;

		// it backs up the value of max profit after doing 'm-1' deals until index 'i' before updating it 
		// to the value of doing 'm' deals until index i
		int prevMaxProfit = 0;

		// k interations for k deals - after each round maxProfitSoFar holds the max profit for 'j' possible deals
		for (int j = 0; j < k; ++j)
		{
			// restting our balance for new iteration
			runningProfit = 0;

			// initializing with the last max profit we are going to start the next iteration with indexes after this
			prevMaxProfit = maxProfitSoFar[j];

			// we don't need to start from the beginning everytime since we would face "the simple case"(above) and the 
			// profit is already calculated. It means that number of deals is greater than the 'len'
			for (int i = j + 1; i < len; ++i)
			{
				// what is the immediate different of the current two prices
				currentProfit = prices[i] - prices[i - 1];

				// is it better to do this deal ? or should we stick to what we did with one less deal and see what future holds!
				runningProfit = max(runningProfit + currentProfit, prevMaxProfit);

				// backing up max value with one less deal to compare in the next round
				prevMaxProfit = maxProfitSoFar[i];

				// updating max profit so far by asking if we gained more profit with last deal or we didn't gain anything more
				maxProfitSoFar[i] = max(runningProfit, maxProfitSoFar[i - 1]);
			}
		}

		// well the last item in the MaxProfitSoFar after k iterations holds max profit
		return maxProfitSoFar[len - 1];
	}

	int maxProfit2(int k, vector<int>& prices)
	{
		if (prices.empty()) return 0;
		int res = 0;
		if (k >= prices.size())
		{
			for (int i = 1; i < prices.size(); ++i)
			{
				if (prices[i] - prices[i - 1] > 0)
					res += prices[i] - prices[i - 1];
			}
		}
		else
		{
			vector<int> local(k + 1);
			vector<int> global(k + 1);

			for (int i = 0; i < prices.size() - 1; ++i)
			{
				int increase = prices[i + 1] - prices[i];
				for (int j = k; j >= 1; --j)
				{
					local[j] = max(global[j - 1] + max(increase, 0), local[j] + increase);
					global[j] = max(global[j], local[j]);
				}
			}
			res = global[k];
		}
		return res;
	}
};





