/*
Given the root of a binary tree, return the zigzag level order traversal of 
its nodes' values. (i.e., from left to right, then 
right to left for the next level and alternate between).
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> bfs;       //stores LEFT TO RIGHT order of next level
        bfs.push(root);
        bool flag = false;
        while(!bfs.empty()) {       
            int n = bfs.size();         
            vector<int> nextLevel;      
            while(n>0){                 
                TreeNode* top = bfs.front();   
                bfs.pop();
                if(top->left) bfs.push(top->left);  
                if(top->right) bfs.push(top->right);  
                nextLevel.push_back(top->val); 
                n--;
            }
            if(flag) reverse(nextLevel.begin(), nextLevel.end());
            ans.push_back(nextLevel);
            flag = !flag;
        }
        return ans;
    }
};

/*
Runtime: 9 ms
Memory: 11.9 MB
*/
