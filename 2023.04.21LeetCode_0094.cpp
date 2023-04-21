// 递归.
class Solution
{
public:
    inline void buildTree(TreeNode *&root, vector<int> &ans)
    {
        if (!root)
            return;
        buildTree(root->left, ans);
        ans.emplace_back(root->val);
        buildTree(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        buildTree(root, ans);
        return ans;
    }
};
// 迭代.
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode *> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.emplace(root);
                root = root->left;
            }
            ans.emplace_back(s.top()->val);
            root = s.top()->right;
            s.pop();
        }
        return ans;
    }
};