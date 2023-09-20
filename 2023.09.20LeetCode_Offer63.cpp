class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int ans = 0;
        int minn = INT_MAX;
        for (const int x : prices) {
            minn = min(minn, x);
            ans = max(ans, x - minn);
        }

        return ans;
    }
};