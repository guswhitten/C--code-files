/*
Given the root of a binary tree, return the level order traversal of 
its nodes' values. (i.e., from left to right, level by level).
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

//using DFS
class Solution {
public:
    vector<vector<int>> answer;
    void dfs(TreeNode* root, int level) {
        if (!root) return;
        if (level == answer.size()) {
            answer.push_back(vector<int> ());
        }
        answer[level].push_back(root->val);
        dfs(root -> left, level+1);
        dfs(root -> right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return answer;
    }
};

/*
Runtime: 15 ms
Memory: 13.6 MB
*/
