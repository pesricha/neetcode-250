#include<bits/stdc++.h>
using namespace std;

/*
We will use a stack based approach. 
1) We will iterate over the asteroids, and set alive = true for each iteration.
2) while stack is not empty and asteroid in the coming iteration is -ve and top is positive.
    a) pop the stack if the incoming has higher absolute value than the current.
    b) else if, it's equal, pop the stack. set alive = false and break out of the loop
    c) else set alive = false and break 
3) if the flag alive is set to be true for the incoming, push it in the stack. 
Do this for all asteroids. 

In the end , reverse push the stack into the array and return.
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int asteroid:asteroids) {
            bool alive = true;
            while(!stack.empty() && asteroid < 0 && stack.top() > 0) {
                if (stack.top() < - asteroid) {
                    stack.pop();
                    continue;
                } else if (stack.top() == -asteroid) {
                    stack.pop();
                }
                alive = false; 
                break;
            }
            if (alive) {
                stack.push(asteroid);
            }
        }

        vector<int> result(stack.size());
        for (int i = stack.size() - 1; i > -1 ; i--) {
            result[i] = stack.top();
            stack.pop();
        }

        return result;
    }
};