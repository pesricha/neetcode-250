#include<bits/stdc++.h>
using namespace std;

/*

1) We can apply a dp such that dp[i] = cost[i] + min(dp[i+1], 
dp[i+2]. We can see that this will work as it'll account for 
the minimum cost for every jump.

*/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2,0);

        for(int i = n - 1; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }

        return min(dp[0], dp[1]);
    }
};
