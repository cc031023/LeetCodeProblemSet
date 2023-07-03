// bfs.
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            ans.emplace_back(vector<int>());
            int now = q.size();
            for (int i = 1; i <= now; ++i) {
                TreeNode* t = q.front();
                q.pop();
                ans.back().emplace_back(t->val);
                if (t->left != nullptr)
                    q.emplace(t->left);
                if (t->right != nullptr)
                    q.emplace(t->right);
            }
        }
        return ans;
    }
};