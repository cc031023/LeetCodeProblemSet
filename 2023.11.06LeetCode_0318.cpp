class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;

        int n = words.size();

        vector<int> sum(n);

        for (int i = 0; i < n; ++i)
            for (const char& x : words[i])
                sum[i] |= 1 << (x - 'a');

        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if ((sum[i] & sum[j]) == 0) res = max(res, int(words[i].length() * words[j].length()));

        return res;
    }
};