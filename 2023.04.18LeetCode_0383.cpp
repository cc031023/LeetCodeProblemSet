class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp1, mp2;
        for (char x : ransomNote)
        {
            ++mp1[x];
        }
        for (char x : magazine)
        {
            ++mp2[x];
        }
        auto it = mp1.begin();
        for (it; it != mp1.end(); ++it)
        {
            if (mp1[it->first] > mp2[it->first])
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
            return false;
        vector<int> cnt(26);
        for (auto &x : magazine)
            ++cnt[x - 'a'];
        for (auto &x : ransomNote)
        {
            --cnt[x - 'a'];
            if (cnt[x - 'a'] < 0)
                return false;
        }
        return true;
    }
};