// z字查询.
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int x = n - 1, y = 0;
        while (x >= 0 && y < m) {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target)
                ++y;
            else
                --x;
        }
        return false;
    }
};

// 二分查询
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const vector<int>& v : matrix) {
            auto it = lower_bound(v.begin(), v.end(), target);
            if (it != v.end() && *it == target)
                return true;
        }
        return false;
    }
};
