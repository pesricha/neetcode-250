#include<bits/stdc++.h>
using namespace std;

/*
1) Start a while loop and get the current digit.
2) if ans > INT_MAX/10 or < INT_MIN/10, adding another digit will cause overflow. return 0.
3) Else set ans = ans*10 + digit. 
4) return ans at the end of the while loop.
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;

            if((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
                return 0;
            }
            ans = ans*10 + digit;
            x = x/10;
        }
        return ans;
    }
};