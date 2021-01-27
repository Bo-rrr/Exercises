class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) return -1;
        unsigned int caddr[128] = {0};
        int pos = 1;
        for (const auto c : str) {
            if (caddr[c] == 0) {
                caddr[c] = pos;
            }
            else {
                caddr[c] = -1;
            }
            ++pos;
        }
        
        for (const auto c : str) {
            if (caddr[c] != -1) return caddr[c]-1;
        }
        return -1;
    }
};