typedef unsigned long long ULL;
class Solution {
public:
    static const int base = 131;
public:
    ULL get(ULL h[], ULL p[], int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        s = ' ' + s;
        ULL h[n + 1], p[n + 1];
        memset(h, 0, sizeof h);
        // 1. 字符串哈希 -> s
        p[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            h[i] = h[i - 1] * base + s[i] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        // 2. 字符串哈希 -> words
        unordered_map<ULL, int> tot;
        for(string& word: words)
        {
            ULL hash = 0;
            for(auto c: word)
                hash = hash * base + c - 'a' + 1;
            tot[hash]++;
        }
        // // 枚举余数？
        for(int i = 1; i <= w; i++)
        {
            int suc = 0;
            unordered_map<ULL, int> window;
            for(int j = i; j + w <= n + 1; j += w)
            {
                if(j >= i + m * w)
                {
                    ULL cur = get(h, p, j - m * w, j - (m - 1) * w - 1);
                    window[cur]--;
                    if(window[cur] < tot[cur]) 
                        suc--;
                }
                ULL cur = get(h, p, j, j + w - 1);
                window[cur] ++;
                if(window[cur] <= tot[cur])
                    suc++;
                if(suc == m)
                    res.push_back(j - (m - 1) * w - 1);
            }
        }
        return res;
    }
};
