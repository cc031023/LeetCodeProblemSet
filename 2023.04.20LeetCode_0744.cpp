class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int l = 0, r = letters.size() - 1;
        char ans = '\0';
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (letters[mid] > target)
            {
                ans = letters[mid];
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans == '\0' ? letters[0] : ans;
    }
};
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
    }
};