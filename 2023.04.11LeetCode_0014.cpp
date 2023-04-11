class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int maxx = strs[0].length();
        int i = 0;
        while (i < maxx)
        {
            char pd = strs[0][i];
            for (auto x : strs)
            {
                if (pd != x[i])
                {
                    return x.substr(0, i);
                }
            }
            ++i;
        }
        return strs[0].substr(0, i);
    }
}; // string类型随便访问不会有越界的说法太牛了.