class Solution {
public:
    int strStr(string haystack, string needle) {
        if ( needle == "" )     //空则返回0
            return 0;
        int hlen = haystack.length();
        int nlen = needle.length();
        int i,j;
        for(i=0;i<hlen;i++){
            for(j=0;j<nlen;j++)
                if(haystack[i+j]!=needle[j])
                    break;      //不符合就结束本轮匹配
            if(j==nlen)
                return i;
        }
        return -1;
    }
};
