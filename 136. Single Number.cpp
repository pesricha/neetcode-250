#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int allXor = 0;
        for (auto num: nums) allXor ^= num;
        return allXor;
};