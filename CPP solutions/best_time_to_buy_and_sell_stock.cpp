class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price_seen = INT_MAX;
        int max_diff_seen = 0;
        for (int i = 0; i < prices.size(); i++)
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