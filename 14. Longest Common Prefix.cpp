#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string base = strs[strs.size()-1];

        for (auto str : strs)
        {   
            int i;
            for (i = 0; i < base.size(); i++)
            {
                if (base[i] != str[i]) break;
            }

            base = base.substr(0,i);
        }
        return base;
    }
};