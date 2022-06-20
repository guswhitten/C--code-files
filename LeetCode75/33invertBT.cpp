/*
Given the root of a binary tree, invert the tree, and return its root.
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

//using SWAP
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};

//without SWAP
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
        
    }
};


/*
Runtime: 0 ms
Memory: 9.8 MB
*/
