class Solution {
public:
    stack<int> stk1,stk2;
    void push(int value) {
        stk1.push(value);
        if(stk2.empty()||stk2.top()>=value){
            stk2.push(value);
        }
    }
    void pop() {
        if(stk1.top()==stk2.top()){
            stk1.pop();
            stk2.pop();
        }
        else stk1.pop();
    }
    int top() {
        return stk1.top();
    }
    int min() {
        return stk2.top();
    }
};
