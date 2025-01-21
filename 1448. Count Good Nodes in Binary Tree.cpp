#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int dfs(TreeNode* root, int maxValue) {
        if (!root) return 0;
        int countBelow = dfs(root->left, max(maxValue, root->val)) +  dfs(root->right, max(maxValue, root->val));
        if (root->val >= maxValue) countBelow++;
        return countBelow;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,-10001);
    }
};