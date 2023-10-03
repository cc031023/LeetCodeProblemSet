class Solution {
private:
    vector<int> ans;
    void dfs(int dex, int now, string val) {
        if (dex == now) {
            ans.emplace_back(stoi(val));
            return;
        }
        for (int i = 0; i <= 9; ++i)
            dfs(dex, now + 1, val + to_string(i));
    }

public:
    vector<int> countNumbers(int cnt) {
        for (int i = 1; i <= cnt; ++i)
            for (int j = 1; j <= 9; ++j)
                dfs(i, 1, to_string(j));

        return ans;
    }
};