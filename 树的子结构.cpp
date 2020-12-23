/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    // 已知相同的根结点，判断这两根结点下的子树是否相同
    bool IsSame(TreeNode *root1, TreeNode *root2)
    {
        // root1是大树   root2是小树
        if(root2 == NULL) return true;
        if(root1 == NULL)  return false;
        
        if(root1->val != root2->val)  return false;
        return IsSame(root1->left, root2->left) && IsSame(root1->right, root2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)  return false;
        bool res = false;
        if(pRoot1->val == pRoot2->val){
            res = IsSame(pRoot1, pRoot2);
        }
        if(res == false) {
            res = HasSubtree(pRoot1->left, pRoot2);
        }
        if(res == false){
            res = HasSubtree(pRoot1->right, pRoot2);
        }
        return res;
    }
};