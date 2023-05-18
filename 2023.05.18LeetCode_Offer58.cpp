class Solution {
   public:
    string reverseWords(string s) {
        if (s == "")
            return "";
        s += ' ';
        string temp;
        stack<string> st;
        for (char& x : s) {
            if (x == ' ') {
                if (!temp.empty()) {
                    st.push(temp);
                    temp.clear();
                }
            } else {
                temp += x;
            }
        }
        temp = "";
        while (!st.empty()) {
            temp += st.top();
            temp += ' ';
            st.pop();
        }
        temp.pop_back();
        return temp;
    }
};