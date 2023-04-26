class Solution
{
public:
    string replaceSpace(string s)
    {
        string ans;
        for (char &x : s)
        {
            if (x == ' ')
                ans += "%20";
            else
                ans += x;
        }
        return ans;
    }
};