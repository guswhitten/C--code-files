/*
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of 
children is separated by the null value (See examples)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* temp = s.top();
            s.pop();
            for (int i = 0; i < temp->children.size(); i++) {
                s.push(temp->children[i]);
            }
            ans.push_back(temp->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Runtime: 34ms
Memory: 11. MB
*/