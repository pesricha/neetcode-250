#include<bits/stdc++.h>
using namespace std;

/*

*/

/**
 * The method uses two queues to keep track of the indices of the senators from both parties.
 * It iterates through the senate string to populate these queues. Then, it simulates the
 * banning process by comparing the indices of the senators at the front of the queues.
 * The senator with the smaller index bans the senator with the larger index and gets
 * re-added to the queue with an updated index. This process continues until one of the
 * queues is empty, indicating that all senators from one party have been banned.
 */
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r_indices, d_indices;

        for (int i = 0; i < n ; i++) {
           senate[i] == 'R' ? r_indices.push(i) : d_indices.push(i);
        }

        while (d_indices.size() && r_indices.size()) {
            int r_index = r_indices.front();
            int d_index = d_indices.front();
            
            r_indices.pop();
            d_indices.pop();

            r_index < d_index ? r_indices.push(r_index + n) : d_indices.push(d_index + n);
        }

        return r_indices.size() ? "Radiant" : "Dire"; 

    }
};