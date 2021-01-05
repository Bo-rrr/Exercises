class Solution {
public:
    int GetUglyNumber_Solution(int index) {
     int ugly_count = 0;    // recording how many Ugly Number has found
    int ugly_buf[index];
    int index2, index3, index5;
    int last2, last3, last5, minium;
     
    if (index < 1)
    { return 0; }
     
    ugly_buf[0] = 1;
    index2 = 0;
    index3 = 0;
    index5 = 0;
    for (ugly_count = 1; ugly_count < index; ugly_count++)
    {
        last2 = ugly_buf[index2] * 2;
        last3 = ugly_buf[index3] * 3;
        last5 = ugly_buf[index5] * 5;
        if (last2 <= last3)    // find the minium value of last2.3.5
        {
            if (last2 <= last5)
            { minium = last2; }
            else
            { minium = last5; }
        }
        else
        {
            if (last3 <= last5)
            { minium = last3; }
            else
            { minium = last5; }
        }
         
        if (last2 == minium)
        { index2++; }
        if (last3 == minium)
        { index3++; }
        if (last5 == minium)
        { index5++; }
         
        ugly_buf[ugly_count] = minium;
    }
    return ugly_buf[index - 1];
    }
};