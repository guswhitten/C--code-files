/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
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

//recursive implementation

class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return v;
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        v.push_back(root -> val);
        return v;
    }
};


//stack implementation
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
    vector<int> v;
    stack<TreeNode*> s;
    if (root == NULL) return v;
    s.push(root);
    TreeNode *p = NULL;
    while(!s.empty()) {
        p = s.top();
        s.pop();
        v.insert(v.begin(), p->val);
        if (p->left) s.push(p->left);
        if (p->right) s.push(p->right);
    }
    
    return v;
    }
};

/*
Runtime 4 ms
Memory 8.5 MB
*/

