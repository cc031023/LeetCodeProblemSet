class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int> ans(n, 1);
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) cur = i;
            son[parents[i]].push_back(i);
        }

        if (cur == -1) return ans;

        int val = 1;
        int preson = cur;
        unordered_set<int> st;
        while (cur != -1) {
            dfs(cur, preson, nums, st);

            for (int i = val; i <= n + 1; ++i) {
                if (st.count(i)) continue;
                ans[cur] = val = i;
                break;
            }

            preson = cur;
            cur = parents[cur];
        }
        return ans;
    }

private:
    unordered_map<int, vector<int>> son;
    void dfs(const int& x, const int& y, vector<int>& v, unordered_set<int>& st) {
        st.insert(v[x]);

        for (const int& now : son[x]) {
            if (now == y) continue;
            dfs(now, y, v, st);
        }
    }
};