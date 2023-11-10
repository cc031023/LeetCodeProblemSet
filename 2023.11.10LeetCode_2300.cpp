class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            double val = ((success * 1.0) / spells[i]);
            int j = lower_bound(potions.begin(), potions.end(), val) - potions.begin();
            ans[i] = m - j;
        }

        return ans;
    }
};