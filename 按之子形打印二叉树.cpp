/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0;
        while(q.size()){
            int n = q.size();
            while(n--){
                auto node = q.front();q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag) 
                reverse(temp.begin(),temp.end());
            res.push_back(temp);
            temp.clear();
            flag = !flag;
        }
        return res;
    }
};