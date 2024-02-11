class Solution {
public:
    int dp[75][75][75];
    
    int helper(int i, int j1, int j2, vector<vector<int>> &grid) {
        if(i >= grid.size() || j1 < 0 || j1 >= grid[0].size() 
            || j2 >= grid[0].size() || j2 < 0) return 0;
        
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int res = grid[i][j1] + grid[i][j2];
        if(j1 == j2) {
            res -= grid[i][j1];
        } 
        
        int temp = max({
            helper(i+1, j1-1, j2-1, grid), 
            helper(i+1, j1-1, j2, grid), 
            helper(i+1, j1-1, j2+1, grid), 
            helper(i+1, j1, j2-1, grid), 
            helper(i+1, j1, j2, grid), 
            helper(i+1, j1, j2+1, grid), 
            helper(i+1, j1+1, j2-1, grid), 
            helper(i+1, j1+1, j2, grid), 
            helper(i+1, j1+1, j2+1, grid)
        });
        
        return dp[i][j1][j2] = temp+res;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof dp);
        int n = grid.size();
        int m = grid[0].size();
        
        return helper(0, 0, m-1, grid);
    }
};