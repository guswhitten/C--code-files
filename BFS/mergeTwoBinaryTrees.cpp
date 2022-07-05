/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of 
the two trees are overlapped while the others are not. You need to merge 
the two trees into a new binary tree. The merge rule is that if two nodes 
overlap, then sum node values up as the new value of the merged node. Otherwise, 
the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        queue<pair<TreeNode*, TreeNode*>> q;                //queue to hold both trees' TreeNode*'s
        if (!root1) return root2;
        if (!root2) return root1;
        q.push({root1, root2});
        while (!q.empty()) {
            auto merged = q.front(); q.pop();
            merged.first->val += merged.second->val;
            if (merged.first->left && merged.second->left) { // check for left children
                q.push({merged.first->left, merged.second->left}); //add to queue
            }
            else if (merged.second->left) {     //if second tree has left child, but first tree doesn't
                merged.first->left = merged.second->left;
            }
            if (merged.first->right && merged.second->right) { // check for right children
                q.push({merged.first->right, merged.second->right}); //add to queue
            }
            else if (merged.second->right) {    //if second tree has right child, but first tree doesn't
                merged.first->right = merged.second->right;
            }
        }
        return root1;
    }
};


/*
Runtime: 72 ms
Memory: 32.5 MB
*/
