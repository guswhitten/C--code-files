/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every 
node differ in height by no more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return (left == -1 || right == -1 || abs(left-right) > 1) ? -1 : max(left, right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

/*
Runtime: 21 ms
Memory: 21 MB
*/
