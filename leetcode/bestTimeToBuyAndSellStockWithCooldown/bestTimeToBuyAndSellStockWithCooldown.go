package bestTimeToBuyAndSellStockWithCooldown

import "math"

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

//buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
//sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。

// buy[i] = max(sell[i-2] - price, buy[i-1])
// sell[i] = max(buy[i-1] + price, sell[i-1])
func maxProfit(prices []int) int {

	max2 := func(a, b int) int {
		if a > b {return a}
		return b
	}

	N := len(prices)
	if N <= 1 {
		return 0
	}


	buy := make([]int, N)
	buy[0] = -prices[0]

	sell := make([]int, N)
	sell[0] = 0

	sell[1] = max2(buy[0] + prices[1], sell[0])
	buy[1] = max2(sell[0] - prices[1], buy[0])

	for i := 2; i < N; i++ {
		buy[i] = max2(sell[i-2] - prices[i], buy[i-1])
		sell[i] = max2(buy[i-1] + prices[i], sell[i-1])
 	}

 	return sell[len(sell) - 1]
}


func maxProfit1(prices []int) int {
	max2 := func(a, b int) int {
		if a > b {return a}
		return b
	}

	N := len(prices)
	if N <= 1 {
		return 0
	}

	buy, preBuy := math.MinInt64, 0
	sell, preSell := 0, 0
	// should write this first and make sure the four variables' value
	for _, price := range prices{
		preBuy = buy
		buy = max2(preSell - price, preBuy)

		preSell = sell
		sell = max2(preBuy + price, preSell)
	}
	return sell
}