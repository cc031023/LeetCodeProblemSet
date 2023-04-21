// 递归.
class Solution
{
public:
    inline void buildTree(TreeNode *&root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        ans.emplace_back(root->val);
        buildTree(root->left, ans);
        buildTree(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ans;
        buildTree(root, ans);
        return ans;
    }
};
// 遍历.
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        TreeNode *p1 = root, *p2 = nullptr;
        vector<int> ans;
        stack<TreeNode *> s;
        while (p1 != nullptr || !s.empty())
        {
            while (p1 != nullptr)
            {
                ans.emplace_back(p1->val);
                s.emplace(p1);
                p1 = p1->left;
            }
            p1 = s.top()->right;
            s.pop();
        }
        return ans;
    }
};