class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() < t.length())
            swap(s, t);
        unordered_map<char, int> mp1, mp2;
        for (char x : s)
            ++mp1[x];
        for (char x : t)
            ++mp2[x];
        auto it = mp1.begin();
        for (it; it != mp1.end(); ++it)
            if (mp1[it->first] != mp2[it->first])
                return false;
        return true;
    }
};
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        vector<int> table(26, 0);
        for (auto &ch : s)
            table[ch - 'a']++;
        for (auto &ch : t)
        {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0)
                return false;
        }
        return true;
    }
};