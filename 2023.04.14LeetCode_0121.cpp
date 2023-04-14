class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        int res = 0;
        deque<int> q; // 维护从小到大.
        q.push_back(0);
        for (int i = 1; i < len; ++i)
        {
            res = max(prices[i] - prices[q.front()], res);
            while (!q.empty() && prices[q.back()] > prices[i])
                q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};