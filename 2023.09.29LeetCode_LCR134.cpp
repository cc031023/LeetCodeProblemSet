class Solution {
private:
    double QuickPow(double x, long long y) {
        double res = 1.0;
        while (y) {
            if (y & 1) res *= x;
            x *= x;
            y >>= 1;
        }
        return res;
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        return N > 0 ? QuickPow(x, N) : 1.0 / QuickPow(x, -N);
    }
};