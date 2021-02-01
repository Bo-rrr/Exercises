class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 1;
        return isSym(pRoot->left, pRoot->right);
    }
    bool isSym(TreeNode* A,TreeNode* B)
    {
        if(A==NULL && B==NULL)
            return 1;
        if(A==NULL || B==NULL)
            return 0;
        if(A->val!=B->val)
            return 0;
        return isSym(A->left,B->right)&&isSym(A->right,B->left);
    }
};v
