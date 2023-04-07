class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        bool pd[127];
        memset(pd, 0, sizeof(pd));
        int i = 1, j = 0;
        pd[s[j]] = true;
        int len = s.length();
        int ans = s[i] == s[j] ? 0 : 1;
        while (i < len)
        {
            while (!pd[s[i]] && i < len)
            {
                pd[s[i]] = true;
                ++i;
            }
            ans = max(ans, i - j);
            pd[s[j++]] = false;
        }
        return ans;
    }
};