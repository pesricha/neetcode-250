#include<bits/stdc++.h>
using namespace std;

/*
1) Append all the tasks with their index so that we can access the index.
2) Sort the tasks list on enq time, proc time, index;
3) initialize time to tasks[0][0]. while (i < n or pq.size() > 0), add all
tasks to pq where their enqueue time is less than t;
4) if still pq.size( == 0), set the current time to enq of the ith task
else pop the first task, execute it and then append time by it's processing time.
*/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<int> ans;
        ans.reserve(n);
        long t;
        
        for (int i = 0 ; i < n ; i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        t = tasks[0][0];
        int i = 0;

        while(pq.size() or i < n)
        {
            while(i < n && t > tasks[i][0])
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if (!pq.size()) t = tasks[i][0];

            else
            {
                pair<int, int> task = pq.top();
                pq.pop();
                ans.push_back(task.second);
                t += task.first;
            }
        }
        return ans;
    }
};