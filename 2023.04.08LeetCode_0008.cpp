class Solution
{
public:
    int myAtoi(string s)
    {
        long long maxx = (1ll << 31ll) - 1;
        long long minn = -(1ll << 31ll);
        long long f = 1;
        int len = s.length();
        bool flag = true;
        long long res = 0;
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == ' ' && flag)
            {
                continue;
            }
            if (s[i] == '-' && flag)
            {
                f = -1;
                flag = false;
                continue;
            }
            if (s[i] == '+' && flag)
            {
                f = 1;
                flag = false;
                continue;
            }
            flag = false;
            if (s[i] < '0' || s[i] > '9')
            {
                if (res * f > maxx)
                {
                    return maxx;
                }
                if (res * f < minn)
                {
                    return minn;
                }
                return res * f;
            }
            flag = false;
            res = (res << 3) + (res << 1) + (s[i] ^ 48);
            if (res * f > maxx)
            {
                return maxx;
            }
            if (res * f < minn)
            {
                return minn;
            }
        }
        return res * f;
    }
};