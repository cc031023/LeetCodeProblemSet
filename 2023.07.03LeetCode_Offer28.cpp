class Solution {
   public:
    bool isTrue(TreeNode* A, TreeNode* B) {
        if (A == nullptr && B == nullptr)
            return true;
        if (A == nullptr || B == nullptr)
            return false;
        return A->val == B->val && isTrue(A->left, B->right) &&
               isTrue(A->right, B->left);
    }

    bool isSymmetric(TreeNode* root) { return isTrue(root, root); }
};
