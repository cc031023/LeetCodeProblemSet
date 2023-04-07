// 法一.
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        int m = nums1.size() - 1;
        int n = nums2.size() - 1;
        int i = 0, j = 0;
        while (i <= m || j <= n)
        {
            if (i <= m && j <= n)
            {
                if (nums1[i] < nums2[j])
                {
                    v.push_back(nums1[i++]);
                }
                else
                {
                    v.push_back(nums2[j++]);
                }
            }
            else if (i > m && j <= n)
            {
                v.push_back(nums2[j++]);
            }
            else
            {
                v.push_back(nums1[i++]);
            }
        }
        int len = v.size();
        return len & 1 ? v[len / 2] : 1.0 * (v[len / 2] + v[len / 2 - 1]) / 2;
    }
};
// 法二.
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
        { // 确保 m ≤ n
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0, right = m, half_len = (m + n + 1) / 2;
        while (left <= right)
        {
            int i = (left + right) / 2; // 在 nums1 中查找第 i 个数
            int j = half_len - i;       // 在 nums2 中查找第 j 个数
            if (i < right && nums2[j - 1] > nums1[i])
            {
                left = i + 1; // 在 nums1 中的区间 [i+1, right] 中查找
            }
            else if (i > left && nums1[i - 1] > nums2[j])
            {
                right = i - 1; // 在 nums1 中的区间 [left, i-1] 中查找
            }
            else
            {
                int max_left = 0;
                if (i == 0)
                    max_left = nums2[j - 1];
                else if (j == 0)
                    max_left = nums1[i - 1];
                else
                    max_left = max(nums1[i - 1], nums2[j - 1]);
                if ((m + n) % 2 == 1)
                    return max_left;
                int min_right = 0;
                if (i == m)
                    min_right = nums2[j];
                else if (j == n)
                    min_right = nums1[i];
                else
                    min_right = min(nums1[i], nums2[j]);
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0; // 不会执行到这里
    }
};