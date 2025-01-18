#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to generate all combinations of k numbers out of 1 to n
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result; // To store the final combinations
        vector<int> combination; // To store the current combination
        backtrack(1, n, k, combination, result); // Start backtracking from 1
        return result; // Return the result containing all combinations
    }

    // Helper function to perform backtracking
    void backtrack(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result){
        // If the current combination is of size k, add it to the result
        if (combination.size() == k)
        {
            result.push_back(combination);
            return;
        }

        // Iterate from the current start number to n
        for (int i = start; i <= n; i++)
        {
            combination.push_back(i); // Add the current number to the combination
            backtrack(i + 1, n, k, combination, result); // Recurse with the next number
            combination.pop_back(); // Remove the last number to backtrack
        }
    }
};