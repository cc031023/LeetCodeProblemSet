class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if (bamboo_len <= 3) return bamboo_len - 1;
        int a = bamboo_len / 3, b = bamboo_len % 3;
        if (b == 0)
            return pow(3, a);
        else if (b == 1)
            return pow(3, a - 1) * 4;
        else
            return pow(3, a) * 2;
    }
};