/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference 
between the values of any two different nodes in the tree.
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
    int dfs(TreeNode*root, int& val, int& mini) {
        if (root->left) dfs(root->left, val, mini);
        if (val>=0) mini = min(mini, root->val - val);
        val=root->val;
        if (root->right) dfs(root-> right, val, mini);
        return mini;
    }
    
    int getMinimumDifference(TreeNode* root) {
        auto mini = INT_MAX, val = -1;
        return dfs(root, val, mini);
    }
};


/*
Runtime: 27 ms
Memory: 25.1 MB
*/
