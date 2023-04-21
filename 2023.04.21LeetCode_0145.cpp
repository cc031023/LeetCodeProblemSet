// 递归.
class Solution
{
public:
    inline void buildTree(TreeNode *const root, vector<int> &ans)
    {
        if (!root)
            return;
        buildTree(root->left, ans);
        buildTree(root->right, ans);
        ans.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == NULL)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left)
                st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right)
                st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};