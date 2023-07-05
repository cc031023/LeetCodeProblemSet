class Solution {
public:
    int getVal(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> q;
        q.emplace(make_pair(0, 0));
        int res = 0;
        bool pd[101][101]{false};
        pd[0][0] = true;
        int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> now = q.front();
            q.pop();
            ++res;
            for (int i = 0; i < 4; ++i) {
                int dx = now.first + dxy[i][0];
                int dy = now.second + dxy[i][1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n) continue;
                if (getVal(dx) + getVal(dy) > k) continue;
                if (pd[dx][dy]) continue;
                pd[dx][dy] = true;
                q.emplace(make_pair(dx, dy));
            }
        }
        return res;
    }
};