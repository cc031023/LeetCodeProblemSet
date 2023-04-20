// 两个栈模拟.
class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue() {}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return {};
        else
        {
            int x = s2.top();
            s2.pop();
            return x;
        }
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty())
            return {};
        else
            return s2.top();
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};
// 双向队列模拟..
class MyQueue
{
public:
    deque<int> q;
    MyQueue() {}

    void push(int x)
    {
        q.push_back(x);
    }

    int pop()
    {
        if (q.empty())
            return {};
        int x = q.front();
        q.pop_front();
        return x;
    }

    int peek()
    {
        if (q.empty())
            return {};
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};
