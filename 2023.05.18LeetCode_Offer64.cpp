// 递归
class Solution {
   public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};

// 用内存算法.
class Solution {
   public:
    int sumNums(int n) { return sizeof(bool[n][n + 1]) >> 1; }
};