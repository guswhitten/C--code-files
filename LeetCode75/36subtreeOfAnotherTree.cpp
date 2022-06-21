/*
Given the roots of two binary trees root and subRoot, return 
true if there is a subtree of root with 
the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a 
node in tree and all of this node's descendants. The tree tree 
could also be considered as a subtree of itself.
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
   bool isSametree(TreeNode* s, TreeNode* t) { 
       if(!s || !t) {                           //if either tree is NULL
           return s==NULL && t==NULL;           //just check if both are NULL, return true if so
       } //now since both are not null check if they have same value otherwise return false
       else if(s->val == t->val) {              //else if both have same value, keep comparing trees          
           return isSametree(s->left,t->left) && isSametree(s->right,t->right);
       }
       else return false;                        //if trees have different values
   }
   bool isSubtree(TreeNode* s, TreeNode* t) {
         if(!s) return false;                   //if main tree is NULL, return false (trees cannot be equal)
         else if (isSametree(s,t)) return true; //call isSametree
         else {
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};



/*
Runtime: 45 ms
Memory: 28.7 MB
*/
