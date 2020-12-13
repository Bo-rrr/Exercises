#include <iostream>
#include <stack>
 
using namespace std;
 
 
template <class T>
class MyQueue
{
public:
    bool empty()const
    {
        return head.empty()&&tail.empty();
    }
    
    void push(T t)
    {
        head.push(t);
    }
    
    //删除对头元素
    //因为queue是一种先进先出，而stack是先进后出，所以需要把head里的数据拷贝到tail中然后再从tail中pop头元素
    void pop()
    {
        if(this->empty())
        {
            //throw exception("队列为NULL");
        }
        while(!head.empty())
        {
            tail.push(head.top());
            head.pop();
        }
        //删除头元素
        tail.pop();
        
        //再将队尾栈容器元素拷贝到队头栈容器中
        while(!tail.empty())
        {
            head.push(tail.top());
            tail.pop();
        }
    }
    
    T& back()
    {
        if(this->empty())
        {
           // throw exception("head is NULL");
        }
        return head.top();
    }
    
    //返回第一个元素
    T& front()
    {
        if(this->empty())
        {
            //throw exception("队列为NULL");
        }
        while(!head.empty())
        {
            tail.push(head.top());
            head.pop();
        }
        
       int tmp =  tail.top();
        
        //再将队尾栈容器元素拷贝到队头栈容器中
        while(!tail.empty())
        {
            head.push(tail.top());
            tail.pop();
        }
 
        return tmp;
    }
    
private:
    stack<int> head;
    stack<int> tail;
};
 
int main()
{
    MyQueue<int> q;
    for(int i=1;i<5;i++)
    {
        q.push(i);
    }
    
    cout<<"front:"<<q.front()<<endl;
    cout<<"back:"<<q.back()<<endl;
    
    return 0;
    }
