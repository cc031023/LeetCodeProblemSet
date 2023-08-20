class Solution {
public:
    static bool cmp(const string& x, const string& y) {
        return x + y < y + x;
    }

    string minNumber(vector<int>& nums) {
        vector<string> v(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            v[i] = to_string(nums[i]);
        sort(v.begin(), v.end(), cmp);
        string ans;
        for (const string& x : v)
            ans += x;
        return ans;
    }
};