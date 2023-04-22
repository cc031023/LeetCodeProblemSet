class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        vector<int> v(2, -1);
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else
            {
                v[0] = mid;
                r = mid - 1;
            }
        }
        if (v[0] != -1)
        {
            for (int i = v[0]; i < (int)nums.size(); ++i)
            {
                if (nums[i] != target)
                {
                    v[1] = i - 1;
                    return v;
                }
            }
            v[1] = nums.size() - 1;
        }
        return v;
    }
};