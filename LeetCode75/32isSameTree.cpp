/*
Given the roots of two binary trees p and q, 
write a function to check if they are the same or not.

Two binary trees are considered the same if they are
structurally identical, and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //if both are NULL, keep DFSing thru trees
        if (p == nullptr && q == nullptr) return true;
      
        //if one is NULL and the other is not, 
        if (p == nullptr || q == nullptr) return false;
        if (p -> val != q -> val) return false;
        if (!isSameTree(p -> left, q-> left)) {
            return false;
        };
        if (!isSameTree(p -> right, q -> right)) {
            return false;
        };
        return true;
    }
};

/*
Runtime: 0 ms
Memory: 10.1 MB
*/
