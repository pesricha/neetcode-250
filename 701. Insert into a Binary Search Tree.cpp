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
public:
   void insertHelper(TreeNode* curr, int val)
    {
        if (curr->val > val && curr->left == nullptr)
        {
            TreeNode* newNode = new TreeNode(val);
            curr -> left = newNode;
            return;
        }

        else if (curr->val < val && curr->right == nullptr)
        {
            TreeNode* newNode = new TreeNode(val);
            curr -> right = newNode;
            return;
        }

        if (curr->val < val) return insertHelper(curr->right, val);
        else return insertHelper(curr->left, val);
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
        {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        insertHelper(root, val);
        return root;
    }
};