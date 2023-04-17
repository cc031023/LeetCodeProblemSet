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