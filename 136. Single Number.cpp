#include<bits/stdc++.h>
using namespace std;

/*
a^a ^ b^b ^ c = 0 ^ 0 ^ c = c
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int allXor = 0;
        for (auto num: nums) allXor ^= num;
        return allXor;
    }
};