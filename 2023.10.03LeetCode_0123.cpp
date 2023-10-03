class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstbuy = -prices[0], firstsell = 0;
        int secondbuy = -prices[0], secondsell = 0;
        for (int i = 1; i < prices.size(); ++i) {
            firstbuy = max(firstbuy, -prices[i]);
            firstsell = max(firstsell, firstbuy + prices[i]);
            secondbuy = max(secondbuy, firstsell - prices[i]);
            secondsell = max(secondsell, secondbuy + prices[i]);
        }

        return secondsell;
    }
};