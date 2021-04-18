class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);//将左子树头结点加入队列
        que.push(root->right);//将右子树头结点加入队列
        while(!que.empty())//接下来判断这两个树是否互相翻转
        {
            TreeNode *leftNode=que.front();
            que.pop();
            TreeNode *rightNode=que.front();
            que.pop();
            if(!leftNode&&!rightNode)//左节点为空，右节点为空，此时说明是对称的
            {
                continue;
            }
            //左右一个节点不为空，或者都不为空，但数值不同，返回false
            if((!leftNode||!rightNode||(leftNode->val!=rightNode->val)))
            {
                return false;
            }
            que.push(leftNode->left);//加入左节点左孩子
            que.push(rightNode->right);//加入右节点右孩子
            que.push(leftNode->right);//加入左节点右孩子
            que.push(rightNode->left);//加入右节点左孩子
        }
        return true;
    }
};
