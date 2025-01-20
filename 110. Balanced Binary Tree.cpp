#include<bits/stdc++.h>
using namespace std;

/*
1) Use a function to get the depth of the tree.
2) Use a preorder like approach to check whether every node is balanced or not.
*/

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
public:
    int depthTree(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = depthTree(node->left);
        int right = depthTree(node->right);
        return max(left, right) + 1;
    }

    bool preorderBalanced(TreeNode* node) {
        if (node == nullptr) return true;
        int left = depthTree(node->left);
        int right = depthTree(node->right);
        if (abs(left - right) > 1) return false;
        bool leftCompute = preorderBalanced(node->left);
        bool rightCompute = preorderBalanced(node->right);
        return leftCompute && rightCompute && true;
    }

    bool isBalanced(TreeNode* root) {
        return preorderBalanced(root);
    }
};