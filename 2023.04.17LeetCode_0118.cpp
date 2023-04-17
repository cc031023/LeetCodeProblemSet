class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows, vector<int>(numRows));
        for (int i = 0; i < numRows; ++i)
        {
            ans[i][0] = 1;
            ans[i][i] = 1;
        }
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 1; j <= i - 1; ++j)
            {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            for (int j = i + 1; j < numRows; ++j)
            {
                ans[i].pop_back();
            }
        }
        return ans;
    }
};