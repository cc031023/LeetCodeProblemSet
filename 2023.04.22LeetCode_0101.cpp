// 递归.
class Solution
{
private:
    inline bool check(TreeNode *x, TreeNode *y)
    {
        if (!x && !y)
            return true;
        if (!x || !y)
            return false;
        return x->val == y->val && check(x->left, y->right) && check(x->right, y->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};
// 迭代.
class Solution
{
public:
    inline bool check(TreeNode *x, TreeNode *y)
    {
        queue<TreeNode *> q;
        q.push(x), q.push(y);
        while (!q.empty())
        {
            TreeNode *a = q.front();
            q.pop();
            TreeNode *b = q.front();
            q.pop();
            if (!a && !b)
                continue;
            if (!a || !b || a->val != b->val)
                return false;
            q.push(a->left), q.push(b->right);
            q.push(a->right), q.push(b->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        return check(root, root);
    }
};
