/*
Given the root of a binary tree, return the average value of the nodes on 
each level in the form of an array. 
Answers within 10-5 of the actual answer will be accepted.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        if (!root) return {{}};
        q.push(root);
        double avg, total, sum;
        
        while (!q.empty()) {
            sum=0;
            int n = q.size();
            total = n;                  //save # of nodes in row to compute avg
            while (n>0) {               //build queue for next row
                TreeNode* top = q.front();
                sum += top->val;        //sum all nodes in the row
                q.pop();
                if (top->left) q.push(top->left);     //build queue for next row
                if (top->right) q.push(top->right);   //build queue for next row
                n--;
            }
            avg=sum/total;
            ans.push_back(avg);
        }
        return ans;
    }
};



/*
Runtime: 15 ms
Memory: 22.4 MB
*/
