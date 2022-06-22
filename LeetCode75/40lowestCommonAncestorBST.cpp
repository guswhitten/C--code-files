/*
Given a binary search tree (BST), find the lowest common 
ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest 
common ancestor is defined between two nodes p and q as the lowest node in T that has both p and
q as descendants (where we allow a node to be a descendant of itself).”
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    bool flag = true;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q, flag);
        return ans;
    }
    
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, bool flag) {
        if (!root) return;
        if (!flag) return;
        if (p->val <= root->val && q->val >= root-> val) {
            ans=root;
            flag=false;
            return;
        }
        else if (p->val >= root->val && q->val <= root-> val) {
            ans=root;
            flag=false;
            return;
        }        
        dfs(root->left, p, q, flag);
        dfs(root->right, p, q, flag);
        return;
        
    }
};

/*
Runtime: 42 ms
Memory: 23.2 MB
*/
