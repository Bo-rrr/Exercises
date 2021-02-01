class Solution {
public:
    string ReverseSentence(string str) {
        vector<string> ret;
        string s;
        for(int i = 0;i<str.size();i++){
            if (str[i]!=' '){
                s+=str[i];
            }
            else{
                ret.push_back(s);
                s = "";
            }
            
        }
        ret.push_back(s);
        s = "";
        for(int i = ret.size()-1;i>=0;i--){
            s+=ret[i];
            s+= i==0?"":" ";
        }
        return s;
    }
};
