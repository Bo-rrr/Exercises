 static const auto io_sync_off=[](){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return nullptr;
    }();

class Solution {
public:
   int InversePairs(vector<int> data){
       if(data.size()<2)
           return 0;
       long long count=0;
       int len=data.size();
       vector<int> tmp(data.begin(),data.end());
       count=InversePairs(data,tmp,0,len-1);
       return count%1000000007;
   }
    private:
   long long InversePairs(vector<int>& data, vector<int>& copy, int low,int high) {
        if (low == high) {
            copy[low] = data[low];
            return 0;
        }
        long long left;
        long long right;
        int length = (high - low) >> 2;
        left = InversePairs(copy,data,low,(low+(length)));
        right = InversePairs(copy,data,(low+(length)+1),high);
        int i = low + (length);
        int j = high;
        int copy_index = high;
        long long count = 0;
        while (i >= low && j >= (low+(length)+1)) {
            if (data[i] > data[j]) {
                count += j - (low + (length));
                copy[copy_index--] = data[i--];
            } else {
                copy[copy_index--] = data[j--];
            }
                
        }
        for (; i >= low; i--) {
            copy[copy_index--] = data[i];
        }
        for (; j>= (low+(length)+1); j--) {
            copy[copy_index--] = data[j];
        }
        return left + count + right;
    }
        
    
};