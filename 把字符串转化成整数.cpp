//剑指offer 49
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    //考虑str为空字符串，只有加减号，数太大溢出，包括其他符号
    //不合法字符返回的0，与真实数字返回的0,怎么区别
    bool isLegal=false;//true 代表返回的0是数值，  false 返回的的0 代表输入的字符串是非法的
    
    int StrToInt(string str) {
        
        if(str.length()==0 )  //str不可以与null 比较，null一般只与char *比较
            return 0;          //str.length()==0  ，str==""   str.empty()表示的含义是是等价的
 
        //if(str == null ||str.length()==0){  //所以str==null会报错
            //return 0;
        //}
        if(str.length()==1 && (str[0]=='+' || str[0]=='-'))
            return 0;
        
        int i=0;//记录str当前位置
        //判断第一位是否位+-
        bool symbol=true; //true:+   false:-
        if(str[0]=='+')
            i++;
        if(str[0]=='-'){
            i++;
            symbol=false;
        }
        
        int digit=0;   
        for(i;i<str.length();i++){
            if(str[i]>='0' && str[i]<='9')
                digit=digit*10+(str[i]-'0');
            else
                return 0;  //出现0--9以外的字符，该字符串不合法，返回0，同时 isLegal=false
           // if(symbol && digit>0x7FFFFFFF)
                //return 0;  //
           // if(!symbol && (-1*digit)<0x80000000)
               // return 0;
            //记住每种类型的范围，很繁琐，C++提供了现成的宏定义
            if(symbol && digit>INT_MAX)
                return 0;  //(signed int )  //作用？
            if(!symbol && (-1*digit)<INT_MIN)
                return 0;
        }
        //遍历到字符串的最后，合法字符
        if(str[i]=='\0')
            isLegal=true;
        if(!symbol)
             return 0-digit;
        else
             return digit;
      
    }
};