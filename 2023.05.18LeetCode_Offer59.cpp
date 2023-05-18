// 模拟双端队列.
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int hh = 0, tt = -1, len = nums.size();
        vector<int> q(len), ans;
        if (len == 0)
            return {};
        for (int i = 0; i < len; ++i) {
            while (hh <= tt && nums[q[tt]] < nums[i])
                --tt;
            q[++tt] = i;
            while (hh <= tt && q[hh] <= i - k)
                ++hh;
            if (i >= k - 1)
                ans.emplace_back(nums[q[hh]]);
        }
        return ans;
    }
};

// 使用stl的deque
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return {};
        vector<int> ans;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            while (!q.empty() && q.front() <= i - k)
                q.pop_front();
            if (i >= k - 1)
                ans.emplace_back(nums[q.front()]);
        }
        return ans;
    }
};