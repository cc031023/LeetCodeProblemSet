class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        int sum = 1;
        int cnt = 0;
        for (auto& x : arrayA) {
            if (x != 0)
                sum *= x;
            else
                ++cnt;
        }

        vector<int> ans;
        for (auto& x : arrayA) {
            if (x != 0 && cnt == 0)
                ans.push_back(sum / x);
            else if (x == 0 && cnt == 1)
                ans.push_back(sum);
            else
                ans.push_back(0);
        }
        return ans;
    }
};