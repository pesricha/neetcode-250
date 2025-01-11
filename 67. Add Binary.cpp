#include<bits/stdc++.h>
using namespace std;
/*
Intuitive. Just take cary = 1 if some of terms at that point is > 1 else 0;
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        
        while(i > -1 || j > -1 || carry)
        {   
            int sum = carry;
            if (i > -1) sum += a[i--] - '0';
            if (j > -1) sum += b[j--] - '0';
            result = to_string(sum%2) + result;
            carry = sum > 1? 1 : 0;
        }
        return result;
    }
};