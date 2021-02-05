class Parenthesis{ 
public:    
	bool chkParenthesis(string A, int n){     
		// write code here        
		stack<char> sc;        
		for (auto ele : A){            
			switch (ele){                
				case '(':                    
					sc.push(ele);                    
					break;                
				case ')':                    
					{                        
						if (sc.empty() || sc.top() != '('){
							return false;
						}                                                   
						else{
							sc.pop();
						}                                                
					}                    
					break;             
				default:                 
					return false;            
				}        
			}        
		return true;    
	} 
};
