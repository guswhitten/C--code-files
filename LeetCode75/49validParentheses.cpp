/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto i:s) {
            if (i=='(' || i=='[' || i=='{') st.push(i); //push opening brackets onto stack
            else {                                      //closing bracket found
                if (st.empty()) return false;
                else if (st.top() == '(' && i != ')') return false;
                else if (st.top() == '[' && i != ']') return false;
                else if (st.top() == '{' && i != '}') return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};

/*
Runtime: 0 ms
Memory: 6.4 MB
*/
