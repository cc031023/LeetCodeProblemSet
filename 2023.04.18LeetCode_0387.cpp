class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> position;
        queue<pair<char, int>> q;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (!position.count(s[i]))
            {
                position[s[i]] = i;
                q.emplace(make_pair(s[i], i));
            }
            else
            {
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1)
                {
                    q.pop();
                }
            }
        }
        return q.empty() ? -1 : q.front().second;
    }
};