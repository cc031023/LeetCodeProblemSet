// 递归.
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int &val)
    {
        if (!root)
            return root;
        if (root->val == val)
            return root;
        TreeNode *ans1 = searchBST(root->left, val);
        if (ans1)
            return ans1;
        TreeNode *ans2 = searchBST(root->right, val);
        return ans2;
    }
};
// 迭代.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int &val)
    {
        if (!root)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *now = q.front();
            q.pop();
            if (now->val == val)
                return now;
            if (now->left)
                q.push(now->left);
            if (now->right)
                q.push(now->right);
        }
        return nullptr;
    }
};