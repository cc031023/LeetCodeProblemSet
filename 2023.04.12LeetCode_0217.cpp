class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int x : nums)
        {
            if (!s.count(x))
            {
                s.insert(x);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};