/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin)
    {
        // 递归出口
        if(pre.empty()||vin.empty())
            return nullptr;
         
        // 建立根节点
        TreeNode *head = new TreeNode(pre[0]);
         
        // 查找中序遍历中根节点的索引值
        int root=0;
        for(int i = 0;i<pre.size();++i)
        {
            if(vin[i] == pre[0])
            {
                root = i;
                break;
            }
        }
        // 先序遍历和中序遍历的左右子树vector
        vector<int> pre_left,pre_right,vin_left,vin_right;
         
        for(int i =0;i<root;++i)
        {
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);
        }
         
        for(int i = root+1;i<pre.size();++i)
        {
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);
        }
         
        // 根节点的左右节点
        head->left = reConstructBinaryTree(pre_left,vin_left);
        head->right = reConstructBinaryTree(pre_right,vin_right);
         
        return head;
    }
};
　　
