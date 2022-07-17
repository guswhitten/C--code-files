/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr = "";
        dfs(root, ans, curr);        
        return ans;
    }
    
    void dfs(TreeNode* root, vector<string>& ans, string curr) {
        if (!root) return;
        curr+=to_string(root->val);
        if (root->left || root->right) curr += "->";
        else ans.push_back(curr);
        
        dfs(root->left, ans, curr);
        dfs(root->right, ans, curr);
    }
private:
    vector<string> ans;
    
};


/*
Runtime: 3 ms
Memory: 14 MB
*/
