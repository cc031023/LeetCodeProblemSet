class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        vector<int> v1, v2;
        for (int i = 0; i < len1; ++i)
            for (int j = 0; j < len2; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    v1.push_back(i);
                    v2.push_back(j);
                }
            }
        for (auto x : v1)
        {
            for (int i = 0; i < len2; ++i)
            {
                matrix[x][i] = 0;
            }
        }
        for (auto x : v2)
        {
            for (int i = 0; i < len1; ++i)
            {
                matrix[i][x] = 0;
            }
        }
    }
};
// 通过确定横竖两个边界来确定中间的数是否为0.
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0])
            {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
