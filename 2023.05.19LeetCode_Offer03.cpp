// 默认第几个数字就是几, 不是就交换到对应位置.
class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

// 简单判重(unordered_set亦可)
class Solution {
   public:
    bool pd[100003]{false};
    int findRepeatNumber(vector<int>& nums) {
        for (int& x : nums)
            if (!pd[x])
                pd[x] = true;
            else
                return x;
        return 0;
    }
};
