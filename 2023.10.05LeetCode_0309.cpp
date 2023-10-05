// 官方题解
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};

// 自己理解后优化版
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        // 分为手上有票, 手上无票有冷却, 手上无票没冷却.

        int buy1 = -prices[0];  // 手上有票的前一天
        int newbuy1 = 0;        // 手上有票当天
        int buy2 = 0;           // 手上无票有冷却的前一天
        int newbuy2 = 0;        // 手上无票有冷却当天
        int buy3 = 0;           // 手上无票没冷却的前一天
        int newbuy3 = 0;        // 手上无票没冷却当天

        for (int i = 1; i < n; ++i) {
            newbuy1 = max(buy1, buy3 - prices[i]);
            newbuy2 = buy1 + prices[i];
            newbuy3 = max(buy2, buy3);

            buy1 = newbuy1;
            buy2 = newbuy2;
            buy3 = newbuy3;
        }

        return max(buy2, buy3);
    }
};