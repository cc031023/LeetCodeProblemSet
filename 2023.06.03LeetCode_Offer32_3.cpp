/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        for (int i = 0; i < ans.size(); ++i) {
            if (i % 2 != 0) {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};