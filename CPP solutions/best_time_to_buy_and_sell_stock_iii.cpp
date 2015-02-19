class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int split = 0;
        int max1, max2;
        int max;
        for (int i = 0; i < prices.size(); i++)
        {
            max1 = maxProfit(prices, 0, i);
            max2 = maxProfit(prices, i + 1, prices.size());
            if (max < max1 + max2)
            {
                max = max1 + max2;
            }
        }
        return max;
    }

    int maxProfit(vector<int> &prices, int from, int to)
    {
        int min_price_seen = INT_MAX;
        int max_diff_seen = 0;
        for (int i = from; i < to; i++)
        {
            if (prices[i] < min_price_seen)
            {
                min_price_seen = prices[i];
            }
            int current_diff = prices[i] - min_price_seen;
            if (current_diff > max_diff_seen)
            {
                max_diff_seen = current_diff;
            }
        }
        return max_diff_seen;
    }

};