class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int sum = 0, res = 0;
        for (const int& x : satisfaction) {
            if (sum + x < 0) break;
            sum += x;
            res += sum;
        }
        return res;
    }
};
