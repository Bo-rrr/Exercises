class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if (matrix.size()==0||matrix[0].size()==0)return result;
        int top=0,bottom=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while(bottom>=top&&right>=left){
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            for(int i=top+1;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            for(int i=right-1;i>left&&bottom>top;i--){
                result.push_back(matrix[bottom][i]);
            }
            for(int i=bottom;i>top&&left<right;i--){
                result.push_back(matrix[i][left]);
            }
            top++;bottom--;left++;right--;
        }
        return result;
    }
};