/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/


class Solution {
private:
    void search(int left, int right, string path, vector<string>& v) {
        if(!left && !right) { v.push_back(path); return ; }
        if(left > 0) search(left-1, right, path+"(", v);
        if(left < right) search(left, right-1, path+")", v);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        search(n, n, "", v);
        return v;
    }
};

/*
Runtime 3 ms
Memory 13.8 MB
*/
