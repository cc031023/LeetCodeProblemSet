class MinStack {
public:
    MinStack() {
        minn.push(INT_MAX);
    }

    void push(int val) {
        st.push(val);
        minn.push(min(minn.top(), val));
    }

    void pop() {
        st.pop();
        minn.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minn.top();
    }

private:
    stack<int> st;
    stack<int> minn;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */