class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (check(tokens[i])) {
                st.push(atoi(tokens[i].c_str()));
            } else {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                switch (tokens[i][0]) {
                    case '+':
                        st.push(num1 + num2);
                        break;
                    case '-':
                        st.push(num1 - num2);
                        break;
                    case '*':
                        st.push(num1 * num2);
                        break;
                    case '/':
                        st.push(num1 / num2);
                        break;
                }
            }
        }
        return st.top();
    }

    bool check(string& s) {
        return !(s == "+" || s == "-" || s == "*" || s == "/");
    }
};
