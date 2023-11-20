class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> mp(n);

        for (const auto& e : edges) {
            mp[e[0]].emplace_back(e[1]);
            mp[e[1]].emplace_back(e[0]);
        }

        vector<int> f(n, -1);

        int x = FindFarPoint(0, f, mp);
        int y = FindFarPoint(x, f, mp);

        vector<int> path;

        // 控制一下结束
        f[x] = -1;

        // 最后一次找到y, 防止f数组出现覆盖犯病(我不确定会不会但是保险很多)
        while (y != -1) {
            path.emplace_back(y);
            y = f[y];
        }

        int ans = path.size();

        return ans % 2 == 0 ? vector<int>{path[ans / 2], path[ans / 2 - 1]} : vector<int>{path[ans / 2]};
    }

private:
    int FindFarPoint(int now, vector<int>& f, vector<vector<int>>& mp) {
        int n = mp.size();

        vector<bool> vis(n);

        int res = -1;

        queue<int> q;
        q.emplace(now);
        vis[now] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res = cur;
            for (const auto& x : mp[cur]) {
                if (!vis[x]) {
                    vis[x] = true;
                    f[x] = cur;
                    q.emplace(x);
                }
            }
        }

        return res;
    }
};