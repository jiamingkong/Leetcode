class Solution:
    # @param prices, a list of integer
    # @return an integer

    def maxProfit(self, prices):
        profit = 0
        for today, yesterday in zip(prices[1:], prices[:-1]):
            diff = today - yesterday
            if diff > 0:
                profit += diff

        return profit
