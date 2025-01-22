#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlphaNumeric(char chr) {
        if ('A' <= chr && chr <= 'Z') return true;
        else if ('a' <= chr && chr <= 'z') return true;
        else if ('0' <= chr && chr <= '9') return true;
        return false;
    }

    bool isPalindrome(string s) {
        int left_pointer = 0;
        int right_pointer = s.size() - 1;

        while (left_pointer < right_pointer)
        {
            while (left_pointer < right_pointer && !isAlphaNumeric(s[left_pointer])) left_pointer++;
            while (left_pointer < right_pointer && !isAlphaNumeric(s[right_pointer])) right_pointer--;

            if (left_pointer >= right_pointer) break;

            if (tolower(s[left_pointer]) != tolower(s[right_pointer])) return false;
            left_pointer++;
            right_pointer--;
        }
        return true;
    }
};