class Solution
{
public:
    int reverse(int x)
    {
        string s;
        int f;
        if (x >= 0)
        {
            f = 1;
        }
        else
        {
            f = -1;
        }
        int res = 0;
        if (x == -2147483648)
        {
            return 0;
        }
        x *= f;
        while (x > 9)
        {
            s += char((x % 10) + 48);
            x /= 10;
        }
        s += char(x + 48);
        int len = s.length();
        bool flag = true;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '0' && flag)
                continue;
            flag = false;
            if ((res == 214748364 && s[i] > '7') || (res > 214748364) && f == 1)
            {
                return 0;
            }
            else if ((res == 214748364 && s[i] > '7') || (res > 214748364) && f == -1)
            {
                return 0;
            }
            res = res * 10 + (s[i] ^ 48);
        }
        return res * f;
    }
};