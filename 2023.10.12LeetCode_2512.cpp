class Solution {
    typedef pair<int, int> PII;
    struct cmp {
        bool operator()(const PII& a, const PII& b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        }
    };

private:
    priority_queue<PII, vector<PII>, cmp> q;
    vector<int> ans;
    unordered_map<string, int> mp;

public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id, int k) {
        for (auto& x : positive_feedback) {
            mp[x] = 3;
        }

        for (auto& x : negative_feedback) {
            mp[x] = -1;
        }

        for (int i = 0; i < report.size(); ++i) {
            int val = 0;
            report[i] += ' ';
            string now;
            for (auto& x : report[i]) {
                if (x == ' ') {
                    if (mp.find(now) != mp.end()) { val += mp[now]; }
                    now.clear();
                } else {
                    now += x;
                }
            }
            q.emplace(make_pair(val, student_id[i]));
        }

        while (k--) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};