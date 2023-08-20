class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int vis = 0;
        for (int i = 0; i < 5; ++i) {
            if (nums[i] == 0) {
                ++cnt;
            } else {
                vis = i;
                break;
            }
        }
        for (int i = vis + 1; i < 5; ++i) {
            if (nums[i] == nums[i - 1]) return false;
            cnt -= nums[i] - nums[i - 1] - 1;
            if (cnt < 0) return false;
        }
        return true;
    }
};