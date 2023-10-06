class Solution {
public:
    int dismantlingAction(string arr) {
        unordered_map<char, bool> mp;
        int res = 0;
        deque<char> q;
        for (auto& x : arr) {
            if (mp[x]) {
                while (mp[x]) {
                    mp[q.front()] = false;
                    q.pop_front();
                }
            }

            mp[x] = true;
            q.push_back(x);

            res = max(res, (int)q.size());
        }

        return res;
    }
};

class Solution {
public:
    int dismantlingAction(string arr) {
        unordered_map<char, int> mp;
        int n = arr.size();
        int i = 0;
        int res = 0;
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            if (mp.find(arr[j]) != mp.end())
                i = mp[arr[j]];
            else
                i = -1;

            mp[arr[j]] = j;
            temp = temp < j - i ? temp + 1 : j - i;
            res = max(res, temp);
        }

        return res;
    }
};