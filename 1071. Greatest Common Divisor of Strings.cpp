#include<bits/stdc++.h>
using namespace std;
/*
1) If str1 + str2 != str2 + str1 there is no common pattern.
If it's equal, then ABCABCABC; ABCABC has the pattern of lenght gcd(9, 6). Return that.
*/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};