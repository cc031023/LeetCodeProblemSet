// 递归.
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
// 迭代.
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        queue<int> q1;
        queue<TreeNode *> q2;
        q1.push(root->val);
        q2.push(root);
        while (!q2.empty())
        {
            TreeNode *now = q2.front();
            q2.pop();
            int val = q1.front();
            q1.pop();
            if (!now->left && !now->right)
            {
                if (targetSum == val)
                    return true;
                continue;
            }
            if (now->left)
            {
                q2.push(now->left);
                q1.push(val + now->left->val);
            }
            if (now->right)
            {
                q2.push(now->right);
                q1.push(val + now->right->val);
            }
        }
        return false;
    }
};
