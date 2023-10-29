class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        for (int i = 0; i < chars.size(); ++i) {
            if (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
                int copy = i;
                int begin = i + 1;

                char x = chars[i];
                while (x == chars[i]) {
                    ++i;
                    if (i == chars.size()) break;
                }

                int end = i - 1;

                int cnt = end - begin + 1;

                string add = to_string(cnt + 1);

                chars.erase(chars.begin() + begin, chars.begin() + begin + cnt);

                reverse(add.begin(), add.end());

                for (const auto& ch : add) {
                    chars.insert(chars.begin() + copy + 1, ch);
                }

                i = copy + add.size();
                res += 1 + add.size();
            } else {
                ++res;
            }
        }
        return res;
    }
};

// 双指针, 前面读后面写
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, left = 0;
        for (int read = 0; read < n; read++) {
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                chars[write++] = chars[read];
                int num = read - left + 1;
                if (num > 1) {
                    int anchor = write;
                    while (num > 0) {
                        chars[write++] = num % 10 + '0';
                        num /= 10;
                    }
                    reverse(&chars[anchor], &chars[write]);
                }
                left = read + 1;
            }
        }
        return write;
    }
};
