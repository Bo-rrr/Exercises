class Solution {
public:
    int cutRope(int number) {
        if(number<=1) return 0;
        if(number==2) return 1;
        if(number==3) return 2;
        int length = number % 3 == 0 ? number / 3 : number / 3 + 1;
        int length1 = number % 3 == 0 ? 0 : 3 - number%3;
        int result=1;
        for(int i=0;i<length1;i++) {
            result=result*2;
        }
        for(int i=0;i<length-length1;i++){
            result=result*3;
        }
        return result;
    }
};
