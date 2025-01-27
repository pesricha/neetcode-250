#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> mainStack;
    stack<int> subStack;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        mainStack.push(x);
    }
    
    int pop() {
        if (!subStack.size()) {
            while(mainStack.size()) {
                subStack.push(mainStack.top());
                mainStack.pop();
            }
        }

        int elem = subStack.top();
        subStack.pop();
        return elem;
    }
    
    int peek() {
        if (!subStack.size()) {
            while(mainStack.size()) {
                subStack.push(mainStack.top());
                mainStack.pop();
            }
        }

        return subStack.top();
        
    }
    
    bool empty() {
        return mainStack.size() == 0 &&  subStack.size() == 0;        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */