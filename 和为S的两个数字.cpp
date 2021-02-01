class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int l = 1, r = 1;
        int tmp = 0;
        while(l <= sum /2){
            if(tmp < sum){
                tmp += r;
                ++r;
            }else if(tmp > sum){
                tmp -= l;
                ++l;
            }
            else{
                vector<int> ans;
                for(int k=l; k<r; ++k){
                    ans.push_back(k);
                }
                res.push_back(ans);
                tmp -= l;
                ++l;
            }
        }
        return res;
    }
};
