// dfs.
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    void dfs(TreeNode* node, int target) {
        if (node == nullptr) return;
        path.emplace_back(node->val);
        target -= node->val;
        if (node->left == nullptr && node->right == nullptr && target == 0) ans.emplace_back(path);
        dfs(node->left, target);
        dfs(node->right, target);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};
// bfs.
class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<TreeNode*, TreeNode*> mp;
    void GetPath(TreeNode* node) {
        vector<int> res;
        while (node != nullptr) {
            res.emplace_back(node->val);
            node = mp[node];
        }
        reverse(res.begin(), res.end());
        ans.emplace_back(res);
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (root == nullptr) return ans;
        queue<int> val;
        queue<TreeNode*> path;
        val.emplace(0);
        path.emplace(root);
        while (!path.empty()) {
            TreeNode* nowpath = path.front();
            path.pop();
            int res = val.front() + nowpath->val;
            val.pop();
            if (res == target && nowpath->right == nullptr && nowpath->left == nullptr) GetPath(nowpath);
            if (nowpath->left != nullptr) {
                mp[nowpath->left] = nowpath;
                path.emplace(nowpath->left);
                val.emplace(res);
            }
            if (nowpath->right != nullptr) {
                mp[nowpath->right] = nowpath;
                path.emplace(nowpath->right);
                val.emplace(res);
            }
        }
        return ans;
    }
};