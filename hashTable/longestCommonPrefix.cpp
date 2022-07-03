/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        string temp;
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i < strs.size(); i++) {
            if (i==0) {
                ans=strs[0];
                continue;
            }
            if (strs[i] == ans) continue;
            int j = 0;
            temp = ans;
            ans = "";
            while (strs[i][j] == temp[j]) {
                ans += temp[j];
                j++;
            }
        }
        return ans;
    }
};

/*
Runtime: 6 ms
Memory: 9.2 MB
*/
