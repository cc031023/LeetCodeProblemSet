// bfs实现树的层序遍历.
class Solution {
   public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while (!q.empty()) {
            TreeNode* now = q.front();
            q.pop();
            if (now == nullptr)
                continue;
            v.emplace_back(now->val);
            if (now->left != nullptr)
                q.emplace(now->left);
            if (now->right != nullptr)
                q.emplace(now->right);
        }
        return v;
    }
};