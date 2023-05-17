// 哈希
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> st;
        for (int& x : nums) {
            st.insert(x);
        }
        for (int& x : nums) {
            if (st.count(target - x))
                return {x, target - x};
        }
        return nums;
    }
};

// 双指针
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target)
                right--;
            else if (nums[left] + nums[right] < target)
                left++;
            else
                return {nums[left], nums[right]};
        }
        return {0, 0};
    }
};
