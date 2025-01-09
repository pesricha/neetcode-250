#include<bits/stdc++.h>
using namespace std;

/*
Start with a slow and fast pointer from the end. Fast moves one step every iteration.
If fast encounters val, it swaps the element with slow and slow moves ahead one step.
By design, this will move all the instances of val at the end of the array.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        int n = nums.size();

        for(fast = 0; fast < n; fast++)
        {
            if (nums[n-1-fast] == val)
            {
                swap(nums[n-1-fast], nums[n-1-slow]);
                slow++;
            }
        } 

        return n-slow;
    }
};