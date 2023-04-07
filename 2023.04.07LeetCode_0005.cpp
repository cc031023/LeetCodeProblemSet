class Solution
{
public:
    struct node
    {
        int x, y;
    };
    inline node spread(string s, int left, int right)
    {
        node now;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        now.x = left + 1, now.y = right - 1;
        return now;
    }
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            node now1 = spread(s, i, i);
            node now2 = spread(s, i, i + 1);
            if (now1.y - now1.x > end - start)
            {
                start = now1.x;
                end = now1.y;
            }
            if (now2.y - now2.x > end - start)
            {
                start = now2.x;
                end = now2.y;
            }
        }
        return s.substr(start, end - start + 1);
    }
};