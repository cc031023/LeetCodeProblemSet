class Solution {
private:
    void DeleteElem(int& pos, int cnt, int& len, vector<int>& nums) {
        for (int i = pos; i < len; ++i) {
            nums[i] = nums[i + cnt];
        }
    }

public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int pos = i + 2;
            while (pos < len && nums[pos] == nums[i]) {
                ++pos;
            }
            len -= pos - i - 2;
            DeleteElem(i, pos - i - 2, len, nums);
        }
        return len;
    }
};

// 妙妙双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) { return n; }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};