// 动态规划法.
class Solution // 类似 dp[i] = max(dp[i - 1] + nums[i], nums[i])
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int pre = 0, ans = nums[0];
        for (int x : nums)
        {
            pre = max(pre + x, x);
            ans = max(ans, pre);
        }
        return ans; // 动态规划法.
    }
};
// 贪心法(跟上面那个挺像的)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int ans = nums[0];
        for (int x : nums)
        {
            if (sum < 0)
            {
                sum = 0;
            }
            sum += x;
            ans = max(sum, ans);
        }
        return ans;
    }
};
// 单调队列优化dp
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        vector<int> v;
        v.push_back(0);
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            v.push_back(v.back() + nums[i]);
        }
        deque<int> q;
        q.push_front(0);
        int ans = -0x3f3f3f3f;
        for (int i = 1; i <= len; ++i)
        {
            ans = max(ans, v[i] - v[q.front()]);
            while (!q.empty() && v[i] < v[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};