#include<bits/stdc++.h>
using namespace std;

/*
Get the bit representation of x. We need n-1 numbers (excluding x) to get the array.
We will generate the bit representation of n-1, and then we will fir the bit represenation of 
n-1 where the bits of x is zero. This way when we take and of all the numbers, we will get the
cumulative and as x;
*/

class Solution {
public:
    long long minEnd(int n, int x) {
        int t = n - 1;
        vector<bool> x_bits(64,0);
        vector<bool> t_bits(64,0);

        int i = 0;
        while(t)
        {
            t_bits[i] = t % 2;
            t = t / 2;
            i++;
        }

        i = 0;
        while(x)
        {
            x_bits[i] = x%2;
            x = x/2;
            i++;
        }
        int j = 0;
        for(int i = 0; i < 64; i++)
        {
            if (x_bits[i] == 0 && j < 64)
            {
                x_bits[i] = t_bits[j];
                j++;
            }
        }
        long long  ans = 0;
        for(int i = 0; i < 64; i++) ans += pow(2,i)*x_bits[i];
        return ans;
    }
};