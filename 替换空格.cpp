class Solution {
  public:
       // 指向字符数组的字符指针str，字符数组长度length
   	void replaceSpace(char *str,int length) {
   
           // 边界检查1：判断字符数组是否为空
   	    if(str==NULL)
               return ;
           // 遍历字符串，统计空格个数、替换前字符个数、替换后字符个数
          int CountOfBlanks=0; // 空格个数
          int Originallength=0;// 替换前字符个数
          int len=0;           // 替换后字符个数
  
          for(int i=0;str[i]!='\0';++i)
          {
              Originallength++;
              if(str[i]==' ')
                  ++CountOfBlanks;
          }
  
          len =Originallength+2*CountOfBlanks;
  
          // 边界检查2：判断字符数组是否越界
          if(len+1>length)
               return ;
  
          // 替换空格
          char*pStr1=str+Originallength;// 字符指针指向原始字符串的末尾
          char*pStr2=str+len;           // 字符指针指向替换后字符串的末尾
  
          while(pStr1 != pStr2)         // 替换结束的条件
          {
              if(*pStr1==' ')
              {
                  *pStr2--='0';
                  *pStr2--='2';
                  *pStr2--='%';
              }
              else
              {
                  *pStr2--=*pStr1;
              }
              --pStr1;
          }
  	}
  };

