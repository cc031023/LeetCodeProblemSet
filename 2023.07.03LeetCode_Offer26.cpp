class Solution {
   public:
    // 判断当前节点是否符合.
    bool isTrue(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        if (A == nullptr || A->val !+B->val)
            return false;
        return isTrue(A->left, B->left) && isTrue(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // 当前节点符合或者A的其它节点符合.
        return (A != nullptr && B != nullptr) &&
               (isSubStructure(A->left, B) || isSubStructure(A->right, B) ||
                isTrue(A, B))
    }
};