#include<bits/stdc++.h>
using namespace std;

/*
1) Just fo a simultaneous preorder traversal with the following base condn.
    return true if both are null
    return false if xor is null
    return false if values dont match
2) call left and right and return left && right && true
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
    
    bool preorderSimultaneous(TreeNode* p_iter, TreeNode* q_iter) {
        if (p_iter == nullptr && q_iter == nullptr) return true;
        if (p_iter == nullptr ^ q_iter == nullptr) return false;
        if (p_iter->val != q_iter->val) return false;
        bool left = preorderSimultaneous(p_iter->left, q_iter->left);
        bool right = preorderSimultaneous(p_iter->right, q_iter->right);
        return left && right && true;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorderSimultaneous(p, q);
    }
};