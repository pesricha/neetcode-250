#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size_1 = word1.size();
        int size_2 = word2.size();
        string sol = "";
        for (int i = 0; i < min(size_1, size_2); i++) {
            sol = sol + word1[i] + word2[i];
        }

        size_1 < size_2 ? sol += word2.substr(size_1, size_2 - size_1) : sol += word1.substr(size_2, size_1 - size_2);

        return sol; 
    }
};