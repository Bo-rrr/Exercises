#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){//输入要考虑多个
        int count=0;
        for(int i=6;i<=n;++i){//外面大循环直接从6开始，因为6是第一个完备数
            int temp=0;
            for(int j=1;j<i;++j){//因子不包括i自己，因为除掉自身的因子
                if(i%j==0){//对于所有的因子累加求和
                    temp+=j;
                }
            }
            if(temp==i){//如果累加和等于当前i，则计数加1
                    ++count;
                }
        }
        cout<<count<<endl;//输出要换行
    }
    return 0;
}