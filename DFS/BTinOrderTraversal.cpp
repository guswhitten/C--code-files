/*

*/

//recurive solution
vector<int> v;
vector<int> inorderTraversal(TreeNode* root) {
    if(root == NULL) {
      return v;
    }
    inorderTraversal(root->left);
    v.push_back(root->val);
    inorderTraversal(root->right);
    return v;
}

/*
Runtime 4 ms
Memory 10.5MB
*/

//stack solution
class Solution {
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;                         //making a stack of TreeNodes
        while(root || !s.empty()) {                 
            if(root != NULL) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();                     //the root has no left children, go back
                s.pop();                            //don't need this node's value to wait in stack
                v.push_back(root->val);             //can simply add it to our output vector
                root = root->right;                 //and check its right children
            }
        }
        return v;
    }
};


