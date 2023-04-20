// 暴力.
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int num = 0;
        for (auto x : grid)
            for (auto y : x)
                num += y < 0;
        return num;
    }
};
// 遍历每一行二分(懒得打了都是模版..)
//---------------------------------------------------------------

// 倒序遍历(O(n + m)的时间复杂度)
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int num = 0, m = (int)grid[0].size(), pos = (int)grid[0].size() - 1;
        for (auto x : grid)
        {
            int i;
            for (i = pos; i >= 0; --i)
            {
                if (x[i] >= 0)
                {
                    if (i + 1 < m)
                    {
                        pos = i + 1;
                        num += m - pos;
                    }
                    break;
                }
            }
            if (i == -1)
            {
                num += m;
                pos = -1;
            }
        }
        return num;
    }
};