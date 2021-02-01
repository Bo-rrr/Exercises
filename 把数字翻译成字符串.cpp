class Solution {
public:
    bool isNumeric(char* string)
    {
        int sz =strlen(string);
        int cntFPoint = 0;
        int cntFE = 0;

//         if(string[0] <'0' || string[0] >'9'){
//             if(string[0] != 'e' && string[0] != 'E' && string[0] != '+' && string[0] != '-' ) {
//                 return false;
//             }
//         }
//         if(string[0] == 0 && string[1] != '.'){
//             return false;
//         }

        for(int i =1;i<sz;i++){
//            cout<<string[i] <<endl;
            if(string[i] == '+' || string[i] =='-'){
                if(string[i-1] != 'e' && string[i-1] != 'E'){
                    return false;
                }
            }else if(string[i] == '.'){
                cntFPoint++;
                if(cntFPoint > 1){
                    return false;
                }
                if(cntFE >=1 ){
                    return false;
                }
            }else if(string[i] == 'e' || string[i] == 'E'){
                cntFE ++;
                if(cntFE > 1){
                    return false;
                }
                
                if(i+1 == sz ){
                    return false;
                }
                
                if(i+1 < sz &&  (string[i+1] <'0' || string[i+1] > '9') ){
                    if(string[i+1] != '+' && string[i+1]!='-'){
                        return false;
                    }
                }
            }else if(string[i] <'0' || string[i] >'9'){
                return false;
            }
        }
        return true;
    }

};
