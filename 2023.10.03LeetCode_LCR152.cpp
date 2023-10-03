class Solution {
private:
    bool Check(vector<int>& postorder, int head, int root) {
        if (head >= root) return true;
        int i = head;
        while (postorder[i] < postorder[root])
            ++i;
        int mid = i;
        while (postorder[mid] > postorder[root])
            ++mid;
        return mid == root && Check(postorder, head, i - 1) && Check(postorder, i, root - 1);
    }

public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return Check(postorder, 0, postorder.size() - 1);
    }
};

class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        stack<int> s;
        int root = INT_MAX;

        for (int i = postorder.size() - 1; i >= 0; --i) {
            if (postorder[i] > root) return false;
            while (!s.empty() && s.top() > postorder[i]) {
                root = s.top();
                s.pop();
            }

            s.push(postorder[i]);
        }

        return true;
    }
};