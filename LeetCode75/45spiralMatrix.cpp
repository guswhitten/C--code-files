/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();          
        int n = matrix[0].size();       
        vector<int> ans;           
        int top = 0, bottom = m, left=0, right=n;
        
        while (top < bottom) {
            for (int i = left; i < right; i++) {    //left to right
                ans.push_back(matrix[top][i]);
            }
            top++;
            if (ans.size() == m*n) break;
            for (int i = top; i < bottom; i++) {    //top to bottom
                ans.push_back(matrix[i][right-1]);
            }
            right--;
            if (ans.size() == m*n) break;
            for (int i = right-1; i >= left; i--) { //right to left
                ans.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for (int i = bottom-1; i >= top; i--) { //bottom to top
                ans.push_back(matrix[i][left]);
            }
            left++;
            if (ans.size() == m*n) break;
        }
        return ans;
        
    }
};


/*
Runtime: 0 ms
Memory: 6.8 MB
*/
