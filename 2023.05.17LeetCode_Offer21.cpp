// 逆天自定义排序.
class Solution {
   public:
    static bool cmp(const int& a, const int& b) { return a % 2 > b % 2; }
    vector<int> exchange(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};

// 遍历
class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> ans;
        for (int& x : nums)
            if (x % 2 == 1)
                ans.emplace_back(x);

        for (int& x : nums)
            if (x % 2 == 0)
                ans.emplace_back(x);
        return ans;
    }
};

// 双指针(快排思想)
class Solution {
   public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right and nums[left] % 2 == 1) {
                left++;
            }
            while (left < right and nums[right] % 2 == 0) {
                right--;
            }
            if (left < right) {
                swap(nums[left++], nums[right--]);
            }
        }
        return nums;
    }
};