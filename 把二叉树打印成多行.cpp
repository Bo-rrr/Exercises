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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> v;
            if(pRoot==NULL)
                return v;
            queue<TreeNode *> q;
            q.push(pRoot);
            while(q.size()!=0)
            {
                vector<int> tmp;
                int n=q.size();
                while(n--)
                {
                    TreeNode* qf=q.front();
                    tmp.push_back(qf->val);
                    q.pop();
                    if(qf->left)//!!!!!!!!!!!!!!!!!!!!!!!
                    q.push(qf->left);
                    if(qf->right) //!!!!!!!!!!!!!!!!!!!!
                    q.push(qf->right);
                }
                //if(!tmp.empty()) /////!!!!!!!!!!!!!!!!
                v.push_back(tmp);
            }
            return v;
        }
    
};