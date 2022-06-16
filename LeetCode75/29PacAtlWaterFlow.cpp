/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches 
the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer 
matrix heights where heights[r][c] represents the height above sea level of the cell 
at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells 
directly north, south, east, and west if the neighboring cell's height is less than 
or equal to the current cell's height. Water can flow from any cell adjacent to an 
ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that 
rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
*/

class Solution {
public:
	int m, n;
    // denotes cells reachable starting from atlantic and pacific edged cells respectively
    vector<vector<bool>> atlantic, pacific;
	vector<vector<int>> ans;    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        if(size(mat) == 0) return ans;
        m = mat.size(), n = mat[0].size();
        
        //set both matrices to false
        atlantic = vector<vector<bool>>(m, vector<bool>(n, false));
        pacific = vector<vector<bool>>(m, vector<bool>(n, false));
        
		// perform dfs from all edge cells (ocean-connected cells)
        // DFS vertically down column 0 (pacific edge left side)
        // then veritcally down column n-1 (atlantic edge right side)
        for(int i = 0; i < m; i++) dfs(mat, pacific, i, 0), dfs(mat, atlantic, i, n - 1);
        
        // DFS horizontally across row 0 (pacific edge top)
        // then horizontally across row m-1 (atlantic edge bottom)
        for(int i = 0; i < n; i++) dfs(mat, pacific, 0, i), dfs(mat, atlantic, m - 1, i);             
        return ans;
    }
    
    
    void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){        
        //
        if(visited[i][j]) return;
        visited[i][j] = true;
		// if cell reachable from both the oceans, insert into final answer vector
        if(atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});    
		// dfs from current cell only if height of next cell is greater
/*⬇️*/  if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
/*⬆️*/  if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
/*➡️*/  if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
/*⬅️*/  if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
};



/*
Runtime: 68 ms
Memory: 24 MB
*/
