// 官方标准是什么自动机, 现在不会只会纯模拟.
// 写的很乱将来可能会重构.
class Solution {
   public:
    bool isNumber(string s) {
        if (s == "")
            return false;
        if (s.length() == 1 && !isdigit(s[0]))
            return false;
        int sign = 0;     // 正负号出现次数.
        int point = 0;    // 小数点出现次数.
        int count_E = 0;  // e出现次数.
        int enumber = 0;
        int space = 0;   // 空格出现次数.
        int number = 0;  // 数字出现次数.
        int len = s.length();
        int i = 0;
        for (i = 0; i < len; ++i) {
            if (s[i] != ' ')
                break;
        }
        int copy = i;
        if (s[i] == 'e' || s[i] == 'E')
            return false;
        if (s[i] == '.' && !isdigit(s[i + 1]))
            return false;
        for (i; i < len; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (space > 0)
                    return false;
                if (sign == 0) {
                    if (i - 1 >= 0) {
                        if (s[i - 1] == 'e' || s[i - 1] == 'E' ||
                            s[i - 1] == ' ')
                            ++sign;
                        else
                            return false;

                    } else if (i == 0) {
                        ++sign;
                    } else {
                        return false;
                    }
                } else if (sign == 1) {
                    if (s[i - 1] != 'e' && s[i - 1] != 'E')
                        return false;
                    ++sign;
                }
            } else if (s[i] == ' ') {
                ++space;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (space > 0)
                    return false;
                if (i - 1 >= 0) {
                    if (isdigit(s[i - 1]) || s[i - 1] == '.') {
                        ++count_E;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if (isdigit(s[i])) {
                if (space > 0)
                    return false;
                if (count_E > 0)
                    ++enumber;
                ++number;
            } else if (s[i] == '.') {
                if (space > 0)
                    return false;
                for (int j = copy; j < i; ++j) {
                    if (s[j] == '+' || s[j] == '-')
                        continue;
                    if (!isdigit(s[j]))
                        return false;
                }
                ++point;
            } else {
                return false;
            }
        }
        if (sign > 2 || count_E > 1 || point > 1 || number < 1 ||
            s.back() == 'e' || s.back() == 'E') {
            return false;
        }
        for (i = len - 1; i >= 0; --i) {
            if (s[i] != ' ')
                break;
        }
        if (!isdigit(s[i]) && s[i] != '.')
            return false;
        return true;
    }
};
