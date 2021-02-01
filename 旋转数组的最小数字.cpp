class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
  int len = rotateArray.size();
  if(len==0)
   return 0;
  for(int i=0;i<len;i++)
  {
   if(rotateArray[i]<0)
    return 0;
  }
  int low = 0,high = len-1;
  int mid;
  while(low<high)
  {
   if(rotateArray[low]<rotateArray[high])
   {
    return rotateArray[low];
   }else
   {
    mid = (low+high)/2;
    if(rotateArray[mid]>rotateArray[high])
    {
     low = mid+1;
    }else if(rotateArray[mid]<rotateArray[high])
    {
     high = mid;
    }
    else
    {
     low++;
    }
   }
  }
  return rotateArray[low];
    }
};
