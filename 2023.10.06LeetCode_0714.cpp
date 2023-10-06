class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int prebuy = -prices[0], presell = 0;
        int nowbuy = 0, nowsell = 0;

        for (auto& x : prices) {
            prebuy = nowbuy = max(prebuy, presell - x);
            presell = nowsell = max(presell, prebuy + x - fee);
        }

        return nowsell;
    }
};