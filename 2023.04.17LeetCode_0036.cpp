class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int l[10][10]{0};
        int h[10][10]{0};
        int sum[3][3][10]{0};
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int now = board[i][j] - '0';
                if (now < 0 || now > 9)
                    continue;
                if (l[j][now] == 0 && h[i][now] == 0 && sum[i / 3][j / 3][now] == 0)
                {
                    l[j][now] = 1;
                    h[i][now] = 1;
                    sum[i / 3][j / 3][now] = 1;
                }
                else
                    return false;
            }
        }
        return true;
    }
};