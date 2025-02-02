#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (auto charcter : s) {
            if (charcter == '(') myStack.push(')');
            else if (charcter == '{') myStack.push('}');
            else if (charcter == '[') myStack.push(']');
            else {
                if (myStack.empty()) return false;
                if (myStack.top() == charcter) myStack.pop();
                else return false;
            }
        }
        return myStack.empty();
    }
};