class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> f(n + 1);
        init(n, f);
        for (const auto& e : edges) {
            if (find(e[0], f) != find(e[1], f))
                merge(e[0], e[1], f);
            else
                return e;
        }
        return {};
    }

private:
    void init(int n, vector<int>& f) {
        for (int i = 1; i <= n; ++i)
            f[i] = i;
    }

    int find(int x, vector<int>& f) {
        return x == f[x] ? x : f[x] = find(f[x], f);
    }

    void merge(int x, int y, vector<int>& f) {
        int fx = find(x, f);
        int fy = find(y, f);
        if (fx != fy) f[fy] = fx;
    }
};