class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int len=numbers.size();
        if(len!=5)return false;
        sort(numbers.begin(),numbers.end());
        int kingNum=0;
        
        int pos=0;
        for(int i=0;i<len;i++)
        {
            if(numbers[i]==0)kingNum++;
            else
            {
                pos=i;
                break;
            }
        }
        for(int i=pos;i<len-1;i++)
        {
            if(numbers[i]==numbers[i+1]) return false;
            kingNum-=(numbers[i+1]-numbers[i]-1);
        }
        if(kingNum<0)return false;
        else return true;
    }
        
};
