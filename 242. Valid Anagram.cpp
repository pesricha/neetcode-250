#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        if (s_size != t_size) return false;
        int arr[26];
        memset(arr, 0, 26);

        for (int i = 0; i < t_size; i++) {
            arr[int(s[i] - 'a')] ++;
            arr[int(t[i] - 'a')] --;
        }

        for (int i = 0; i < 26; i++) {
            if(arr[i]) return false;
        }
        
        return true;
    }
};