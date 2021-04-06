class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        
        vector<int> dp(s.size()+1, 1);
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == '0')
            {
                if(s[i-1] != '1' && s[i-1] != '2') return 0;
                dp[i+1] = dp[i-1];
                continue;
            }

            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7'))
                dp[i+1] = dp[i] + dp[i-1];
            else
                dp[i+1] = dp[i];
        }
        return dp[s.size()];
    }
};
