class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        return !left ? right : (!right ? left : root);
    }
};

class Solution {
private:
    unordered_map<int, bool> vis;
    unordered_map<int, TreeNode*> f;

    void dfs(TreeNode* root) {
        if (root->left) {
            f[root->left->val] = root;
            dfs(root->left);
        }

        if (root->right) {
            f[root->right->val] = root;
            dfs(root->right);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root;
        f[root->val] = nullptr;
        dfs(root);
        while (p) {
            vis[p->val] = true;
            p = f[p->val];
        }

        while (q) {
            if (vis[q->val]) return q;
            q = f[q->val];
        }

        return root;
    }
};