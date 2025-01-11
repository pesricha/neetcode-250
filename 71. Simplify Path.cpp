#include<bits/stdc++.h>
using namespace std;

/*
Brute force approach. Maintain a string newPath that contains sum of all chars that are not
'/'. If we encounter a '/' and newPath is non empty and does not have "." or "..", we push it 
to the stack and reset newPath. If it's "." we skip and reset and if it's ".." we pop and reset.
If stack is empty, we jsut treset instead of pop and then reconstruct the path from the stack.
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string newPath = "";
        int n = path.size();
        int l = 0;
        for ( int i = 0; i <= n; i++)
        {
            if(path[i] != '/' && i < n) newPath += path[i];
            else if (newPath != "")
            {
                if(newPath != "." && newPath != "..")
                {
                    st.push(newPath);
                    newPath = "";
                }

                else if (newPath == ".") 
                {
                    newPath = "";
                    continue;
                }

                else
                {
                    if (st.size()) st.pop();
                    newPath = "";
                }
                
            }
            else continue;
        }

        if (!st.size()) return "/";

        string finalPath = "";

        while(st.size())
        {
            finalPath = "/" + st.top() + finalPath;
            st.pop();
        }

        return finalPath;
    }
};