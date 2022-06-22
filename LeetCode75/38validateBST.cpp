/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    vector<int> ascending;
    int i = 0;
    bool flag = true;
    bool isValidBST(TreeNode* root) {
        if (!root) return false;
        isValidBST(root->left);         // in-order traversal
        i++;                            // vector size
        ascending.push_back(root->val); // vector to order elements
        if (ascending.size()>1) {
            if (ascending[i-1] <= ascending[i-2]) { //compare size
                return (flag = false);
            }
        }
        isValidBST(root->right);
        if (!flag) return false;
        return true;
    }
};


/*
Runtime: 19 ms
Memory: 21.9 MB
*/
