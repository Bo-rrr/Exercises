/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    void minorder(TreeLinkNode* root, vector<TreeLinkNode*> &v){
        if(!root)
            return;
        if(root->left)
            minorder(root->left,v);
        v.push_back(root);
        if(root->right)
            minorder(root->right,v);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        vector<TreeLinkNode*> v;
        if(!pNode)
            return nullptr;
        TreeLinkNode*  cur = pNode;
        TreeLinkNode* root = nullptr;
        while(cur){
            root= cur;
            cur =cur->next;
        }
        minorder(root,v);
        for(int i =0;i<v.size();i++){
            if(v[i]==pNode && i+1<v.size())
                return v[i+1];
        }
        return nullptr;
        
    }
};