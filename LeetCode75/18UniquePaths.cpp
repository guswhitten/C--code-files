/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/



class Solution {
public:
    int uniquePaths(int m, int n) {
        
        //create m x n matrix of all 1's
        vector<vector<int>> dp(m, vector<int>(n, 1));  
        
        //two FOR loops to iterate thru whole 2d matrix
        for (int i = 1; i < m; i++) {       //row #
            for (int j = 1; j < n; j++) {   //col #
                
                //each square is simply the sum of the ones above and to the left of it
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];     
            }
        }
        
        //return the bottom right cell of the matrix
        return dp[m - 1][n - 1];
    }
};


/*
Runtime: 0ms
Memory: 6.6 MB
*/
