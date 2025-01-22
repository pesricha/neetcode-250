#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size_nums = nums.size();
        if(size_nums < 2) return size_nums;
        int prev_index = 0;
        int counter = 0;
        int i = 0;

        while(i < size_nums) {
            while(i < size_nums && nums[i] == nums[prev_index]) i++;
            if(i>size_nums) break;
            nums[prev_index + 1] = nums[i];
            prev_index++;  
            counter++;
        }
        return counter;
    }
};