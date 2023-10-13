class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), 1);
        unordered_map<int, int> mp;
        set<int> st;

        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                st.insert(i);
            } else {
                res[i] = -1;
                if (mp.find(rains[i]) != mp.end()) {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it == st.end()) return {};
                    res[*it] = rains[i];
                    st.erase(it);
                }

                mp[rains[i]] = i;
            }
        }

        return res;
    }
};