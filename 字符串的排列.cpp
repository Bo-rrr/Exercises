class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.size()==0) return res;
        permutations(str,0,str.size(),res);
        return res;
    }
    void permutations(string str,int index,int len,vector<string> &res)
    {
        if(index==len-1){
            res.push_back(str);
            return ;
        }
        for(int i=index;i<len;i++)
        {
            if(i!=index && str[i]==str[index])
                continue;
            swap(str[i],str[index]);
            permutations(str,index+1,str.size(),res);
        }
    }
};