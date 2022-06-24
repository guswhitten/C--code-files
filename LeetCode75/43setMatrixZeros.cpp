/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rowMarker(matrix.size(), 1);
        vector<int> colMarker(matrix[0].size(), 1);
        
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    rowMarker[i] = 0;
                    colMarker[j] = 0;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (rowMarker[i]==0) {
                    matrix[i][j] = 0;
                }
                if (colMarker[j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }    
    }
};

/*
Runtime: 30 ms
Memory: 13.3 MB
*/
