/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        
        //create a padded dynamic programming matrix
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        //iterate thru matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                //compare every letter in text2 to i-th letter in text1
                if (text1[i] == text2[j]) {
                    
                    //if they're equal, +1 from square diagonally top-left
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                
                else {
                    
                    //otherwise, just carry the max longest sequence from square above or to the left
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        
        //return bottom right square of matrix
        return dp[m][n];        
    }
};



/*
Runtime: 60ms
Memory: 13 MB
*/
