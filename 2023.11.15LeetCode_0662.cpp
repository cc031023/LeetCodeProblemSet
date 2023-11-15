class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned int res = 0;
        unordered_map<TreeNode*, unsigned int> mp;
        queue<TreeNode*> q;
        q.emplace(root);
        mp[root] = 1;
        while (!q.empty()) {
            int n = q.size();
            vector<unsigned int> v;
            for (int i = 0; i < n; ++i) {
                TreeNode* now = q.front();
                q.pop();
                v.push_back(mp[now]);
                if (now->left) {
                    q.emplace(now->left);
                    mp[now->left] = mp[now] << 1;
                }

                if (now->right) {
                    q.emplace(now->right);
                    mp[now->right] = mp[now] << 1 | 1;
                }
            }
            res = max(res, v.back() - v[0] + 1);
        }

        return res;
    }
};