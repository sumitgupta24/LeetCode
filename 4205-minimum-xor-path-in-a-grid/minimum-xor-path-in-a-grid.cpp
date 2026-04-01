class Solution {
public:
    
    int solve(int i, int j, int xorr, vector<vector<int>>& grid, vector<vector<vector<long long>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m) return 1e9;
        if(i == n - 1 && j == m - 1){
            return xorr ^ grid[i][j];
        }
        if(dp[i][j][xorr] != -1) return dp[i][j][xorr];
        int right = solve(i, j + 1, xorr ^ grid[i][j], grid, dp);
        int down = solve(i + 1, j, xorr ^ grid[i][j], grid, dp);
        return dp[i][j][xorr] = min(right, down);
    }
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(1025, -1LL)));
        return solve(0, 0, 0, grid, dp);
    }
};