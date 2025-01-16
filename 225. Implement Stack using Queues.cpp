#include<bits/stdc++.h>
using namespace std;

/*
1) push is just normal push
2) for pop, cycle the queue size() - 1 times and then remove the last element
3) for top, return the last element similar to pop but before returning push it back
4) for empty, just return !size()
*/

class MyStack {
private:
queue<int> Q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        Q.push(x);
    }
    
    int pop() {
        int n = Q.size() - 1;
        while(n--)
        {
            int elem = Q.front();
            Q.pop();
            Q.push(elem);
        }

        int elem = Q.front();
        Q.pop();
        return elem;
    }
    
    int top() {
        int n = Q.size() - 1;
        while(n--)
        {
            int elem = Q.front();
            Q.pop();
            Q.push(elem);
        }

        int elem = Q.front();
        Q.pop();
        Q.push(elem);
        return elem;
    }
    
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */