class Solution {
public:
    int crackNumber(int ciphertext) {
        string cur = to_string(ciphertext);
        if (cur.size() == 1) return 1;
        vector<int> dp(cur.size());
        dp[0] = dp[1] = 1;
        string val;
        val += cur[0];
        val += cur[1];
        int check = stoi(val);
        if (check <= 25 && check >= 10) dp[1] += dp[0];
        for (int i = 2; i < cur.size(); ++i) {
            dp[i] = dp[i - 1];
            string val;
            val += cur[i - 1];
            val += cur[i];
            int check = stoi(val);
            if (check <= 25 && check >= 10) dp[i] += dp[i - 2];
        }
        return dp[cur.size() - 1];
    }
};