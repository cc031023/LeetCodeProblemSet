class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp1, mp2;
        for (int x : nums1)
        {
            ++mp1[x];
        }
        for (int x : nums2)
        {
            ++mp2[x];
        }
        auto it = mp1.begin();
        vector<int> v;
        for (it; it != mp1.end(); it++)
        {
            int n = it->first;
            int sum = min(it->second, mp2[it->first]);
            while (sum--)
            {
                v.push_back(n);
            }
        }
        return v;
    }
};