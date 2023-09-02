class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.emplace(x);
    }

    int pop() {
        for (int i = 1; i < q.size(); ++i) {
            q.emplace(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        for (int i = 1; i < q.size(); ++i) {
            q.emplace(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        q.emplace(res);
        return res;
    }

    bool empty() {
        return q.empty();
    }
};