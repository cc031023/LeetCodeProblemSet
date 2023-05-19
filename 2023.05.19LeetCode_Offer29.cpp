// 模拟.
class Solution {
   public:
    bool pd[103][103]{false};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();  // 行
        if (n == 0)
            return {};
        int m = matrix[0].size();  // 列
        if (m == 0)
            return {};
        if (n == 1)
            return matrix[0];
        int x = 0, y = 0;
        while (true) {
            if (ans.size() == n * m)
                break;
            // 右
            while (y < m && !pd[x][y]) {
                pd[x][y] = true;
                ans.emplace_back(matrix[x][y++]);
            }
            --y, ++x;
            // 下
            while (true) {
                if (pd[x][y] || x >= n)
                    break;
                ans.emplace_back(matrix[x][y]);
                pd[x++][y] = true;
            }
            --x, --y;
            // 左
            while (y >= 0 && !pd[x][y]) {
                pd[x][y] = true;
                ans.emplace_back(matrix[x][y--]);
            }
            ++y, --x;
            // 上
            while (true) {
                if (x < 0 || pd[x][y])
                    break;
                ans.emplace_back(matrix[x][y]);
                pd[x--][y] = true;
            }
            ++x, ++y;
        }
        return ans;
    }
};