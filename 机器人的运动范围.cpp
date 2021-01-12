class Solution {
public:
    vector<int> gewei(int x){
        vector<int> shuwei;
        if(x<10)
            shuwei.push_back(x);
        else if(x<100){
            shuwei.push_back(x/10);
            shuwei.push_back(x%10);
        }
        else if(x<1000){
            shuwei.push_back(x/100);
            shuwei.push_back(x%100/10);
            shuwei.push_back(x%100%10);
        }
        return shuwei;
    }
    int sum(vector<int> vec){
        int len=vec.size();
        int res=0;
        for(int i=0;i<len;i++){
            res+=vec[i];
        }
        return res;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        int count=0;
        int resi,resj;
        for(int i=0;i<rows;i++){
            if(sum(gewei(i))>threshold)
                break;
            for(int j=0;j<cols;j++){
                resi=sum(gewei(i));
                resj=sum(gewei(j));
                if(resi+resj<=threshold){
                    count++;
                }
                else if(rows==1)
                    break;
            }
        }
        return count;
    }
};