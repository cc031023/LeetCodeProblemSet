class Solution {
public:
    vector<vector<int>> fileCombination(int target) {
        vector<vector<int>> res;
        deque<int> q;
        int sum = 0;
        for (int i = 1; i <= target / 2 + 1; ++i) {
            q.push_back(i);
            sum += i;
            while (sum > target) {
                sum -= q.front();
                q.pop_front();
            }
            if (sum == target) {
                vector<int> v;
                for (const int& x : q) {
                    v.push_back(x);
                }
                res.emplace_back(v);
            }
        }
        return res;
    }
};