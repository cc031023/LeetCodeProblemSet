class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        long long res = 0;
        for (const auto& x : nums) {
            q.push(x);
        }
        while (k--) {
            int now = q.top();
            q.pop();
            res += now;
            q.push(ceil(now * 1.0 / 3));
        }

        return res;
    }
};