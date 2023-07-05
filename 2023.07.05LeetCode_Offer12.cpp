class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        int ans = word.size() - 1;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (dfs(board, word, i, j, 0, ans)) return true;
        return false;
    }

private:
    int row, col;
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int vis, int& ans) {
        if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != word[vis]) return false;
        if (vis == ans) return true;
        board[x][y] = '\0';
        bool res = dfs(board, word, x + 1, y, vis + 1, ans) || dfs(board, word, x - 1, y, vis + 1, ans) ||
                   dfs(board, word, x, y + 1, vis + 1, ans) || dfs(board, word, x, y - 1, vis + 1, ans);
        board[x][y] = word[vis];
        return res;
    }
};