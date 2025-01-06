#include<bits/stdc++.h>
using namespace std;

/*
    * If target is outside the search space, we return 0 or n appropriately.
    * else we start standard binary search and return index of target if found
    * If target is not found, we return the low index.
    *
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int high = nums.size() - 1;
        int low = 0;
        int mid;
        
        while(low <= high) {
            mid = low + (high - low)/2;
            if (target == nums[mid]) {
                return mid;
            }
            if(target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1; 
            }
        }

        if (target < nums[left]) return left;
        return left + 1;
    }
};
