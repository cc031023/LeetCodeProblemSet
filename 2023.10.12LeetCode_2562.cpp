class Solution {
private:
    static const long long GetVal(int x, int y, vector<int>& nums) {
        if (x == y) {
            return nums[x];
        } else {
            string s = to_string(nums[x]) + to_string(nums[y]);
            return stoi(s);
        }
    }

public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int head = 0, tail = nums.size() - 1;

        while (head <= tail) {
            res += GetVal(head++, tail--, nums);
        }

        return res;
    }
};