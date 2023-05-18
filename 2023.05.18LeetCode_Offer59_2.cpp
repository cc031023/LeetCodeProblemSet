// 用单调队列维护最大值.
class MaxQueue {
   public:
    deque<int> maxx;
    queue<int> q;
    MaxQueue() {}

    int max_value() {
        if (!maxx.empty())
            return maxx.front();
        else
            return -1;
    }

    void push_back(int value) {
        q.push(value);
        while (!maxx.empty() && maxx.back() < value)
            maxx.pop_back();
        maxx.push_back(value);
    }

    int pop_front() {
        if (q.empty()) {
            return -1;
        } else {
            if (!maxx.empty() && maxx.front() == q.front())
                maxx.pop_front();
            int temp = q.front();
            q.pop();
            return temp;
        }
    }
};

// 数组模拟暴力遍历.
class MaxQueue {
    int q[20000];
    int begin = 0, end = 0;

   public:
    MaxQueue() {}

    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; ++i)
            ans = max(ans, q[i]);
        return ans;
    }

    void push_back(int value) { q[end++] = value; }

    int pop_front() {
        if (begin == end)
            return -1;
        return q[begin++];
    }
};
