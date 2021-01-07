class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);
        for (int i=1; i<A.size(); ++i) {
            B[i] = B[i-1] * A[i-1]; // left[i]用B[i]代替
        }
        int tmp = 1;
        for (int j=A.size()-2; j>=0; --j) {
            tmp *= A[j+1]; // right[i]用tmp代替
            B[j] *= tmp;
        }
        return B;
    }
};