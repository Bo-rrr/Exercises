class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        if (root == nullptr) return -1;
        if (root->val == o1 || root->val == o2) return root->val;
        
        int left = lowestCommonAncestor(root->left, o1, o2);
        int right = lowestCommonAncestor(root->right, o1, o2);
        
        if (left != -1 && right != -1) return root->val;
        else if (left != -1) return left;
        else if (right != -1) return right;
        else return -1;
    }
};
