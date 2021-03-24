class Solution {
public:
    vector<int> grayCode(int n) {
         vector<int> ans={0};
        if(n==0)
            return ans;
        ans ={0,1 };
        for(int i=1 ;i<n ;i++ ){
            int lenth = ans.size();
            int addi = (1<<i);
            for( int j=0;j<lenth ;j++ ){
                ans.push_back( ans[ lenth- j-1]+addi );
            }
        }
        return ans;
    }
};
