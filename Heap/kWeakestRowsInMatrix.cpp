/*
You are given an m x n binary matrix mat of 1's (representing soldiers) 
and 0's (representing civilians). The soldiers are positioned in front of 
the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        for(int i=0; i<mat.size(); i++) {   // append index to end of row (to decide ties)
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end());       // sorting moves smallest rows to top (ascending order)
        vector<int> ans(k);                 // create new array with only K elements
        for(int i=0; i<k; i++){             //
            ans[i]=mat[i][n];            
        }
        return ans;
    }
};

/*
Runtime: 28 ms
Memory: 10.4 MB
*/
