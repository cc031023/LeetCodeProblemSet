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
class Solution {
private:
    vector<int> pre;
    unordered_map<int, int> mp;
    TreeNode* BuildTree(int root, int l, int r) {
        if (l > r) return nullptr;
        int i = mp[pre[root]];
        TreeNode* newnode = new TreeNode(pre[root]);
        newnode->left = BuildTree(root + 1, l, i - 1);
        newnode->right = BuildTree(root + 1 + i - l, i + 1, r);
        return newnode;
    }

public:
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        return BuildTree(0, 0, inorder.size() - 1);
    }
};