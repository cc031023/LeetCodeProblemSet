class Solution {
   public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* now = q.front();
            q.pop();
            swap(now->left, now->right);
            if (now->left != nullptr)
                q.emplace(now->left);
            if (now->right != nullptr)
                q.emplace(now->right);
        }
        return root;
    }
};