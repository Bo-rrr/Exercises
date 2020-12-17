 1 class Solution {
  2 public:
  3     // 指向字符数组的字符指针str，字符数组长度length
  4 	void replaceSpace(char *str,int length) {
  5 
  6         // 边界检查1：判断字符数组是否为空
  7 	    if(str==NULL)
  8             return ;
  9         // 遍历字符串，统计空格个数、替换前字符个数、替换后字符个数
 10         int CountOfBlanks=0; // 空格个数
 11         int Originallength=0;// 替换前字符个数
 12         int len=0;           // 替换后字符个数
 13 
 14         for(int i=0;str[i]!='\0';++i)
 15         {
 16             Originallength++;
 17             if(str[i]==' ')
 18                 ++CountOfBlanks;
 19         }
 20 
 21         len =Originallength+2*CountOfBlanks;
 22 
 23         // 边界检查2：判断字符数组是否越界
 24         if(len+1>length)
 25              return ;
 26 
 27         // 替换空格
 28         char*pStr1=str+Originallength;// 字符指针指向原始字符串的末尾
 29         char*pStr2=str+len;           // 字符指针指向替换后字符串的末尾
 30 
 31         while(pStr1 != pStr2)         // 替换结束的条件
 32         {
 33             if(*pStr1==' ')
 34             {
 35                 *pStr2--='0';
 36                 *pStr2--='2';
 37                 *pStr2--='%';
 38             }
 39             else
 40             {
 41                 *pStr2--=*pStr1;
 42             }
 43             --pStr1;
 44         }
 45 	}
 46 };
