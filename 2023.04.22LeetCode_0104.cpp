// 迭代.
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> q;
        q.push(pair(root, 1));
        int ans = 1;
        while (!q.empty())
        {
            pair<TreeNode *, int> p = q.front();
            q.pop();
            if (ans < p.second)
                ans = p.second;
            if (p.first->left)
                q.push(pair(p.first->left, p.second + 1));
            if (p.first->right)
                q.push(pair(p.first->right, p.second + 1));
        }
        return ans;
    }
};
// 麻烦的递归.
class Solution
{
public:
    inline void buildTree(TreeNode *&root, int &ans, int dex)
    {
        if (!root)
            return;
        ans = max(ans, dex);
        buildTree(root->left, ans, dex + 1);
        buildTree(root->right, ans, dex + 1);
    }
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        buildTree(root, ans, 1);
        return ans;
    }
};
// 简洁的递归.
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
