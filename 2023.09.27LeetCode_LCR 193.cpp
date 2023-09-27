
class Solution {
private:
    static vector<TreeNode*> GetPath(TreeNode* root, TreeNode* cur) {
        vector<TreeNode*> path;

        while (root != cur) {
            path.emplace_back(root);
            if (root->val > cur->val)
                root = root->left;
            else
                root = root->right;
        }

        path.emplace_back(root);

        return path;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = GetPath(root, p);
        vector<TreeNode*> path2 = GetPath(root, q);
        TreeNode* ans = nullptr;

        for (int i = 0; i < path1.size() && i < path2.size(); ++i) {
            if (path1[i] != path2[i]) return ans;
            ans = path1[i];
        }

        return ans;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val)
                ancestor = ancestor->left;
            else if (p->val > ancestor->val && q->val > ancestor->val)
                ancestor = ancestor->right;
            else
                break;
        }
        return ancestor;
    }
};
