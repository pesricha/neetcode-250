#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;

        int zero = 0, one = 1, two = 1, three;
        
        for (int i = 3; i < n+1 ; i++) {
            three =  zero + one + two;
            zero = one;
            one = two;
            two = three;
        }
        return three;
    }
};