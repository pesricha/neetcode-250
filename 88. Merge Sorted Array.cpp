#include<iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iter1 = m - 1;
        int iter2 = n - 1;
        int inserter = m + n - 1;

        while(iter1 > -1 && iter2 > -1) {
            if(nums1[iter1] >= nums2[iter2]) {
                nums1[inserter] = nums1[iter1];
                iter1--;
                inserter--;
            }

            else {
                nums1[inserter] = nums2[iter2];
                iter2--;
                inserter--;
            }
        }

        while(iter2 > -1) {
            nums1[iter2] = nums2[iter2];
            iter2--;
        }
        return;
    }
};
