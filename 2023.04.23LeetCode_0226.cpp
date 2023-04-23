// 递归.
class Solution
{
public:
    inline void reverseTree(TreeNode *&root)
    {
        if (!root)
            return;
        swap(root->left, root->right);
        reverseTree(root->left);
        reverseTree(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        reverseTree(root);
        return root;
    }
};
// 迭代.
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *now = q.front();
            q.pop();
            swap(now->left, now->right);
            if (now->left)
                q.push(now->left);
            if (now->right)
                q.push(now->right);
        }
        return root;
    }
};