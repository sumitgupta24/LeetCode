class Solution {
public:
    int solve(int i,int j,int cost,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m) return INT_MIN;
        int currCost = grid[i][j] == 0 ? 0 : 1;
        if(cost < currCost) return INT_MIN;
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }
        if(dp[i][j][cost] != -1) return dp[i][j][cost];
        
        int right = solve(i,j+1,cost - currCost,grid,dp);
        int down = solve(i+1,j,cost - currCost,grid,dp);
        
        if(right == INT_MIN && down == INT_MIN) return dp[i][j][cost] = INT_MIN;
        return dp[i][j][cost] = grid[i][j] + max(right,down);
    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int answer = solve(0,0,k,grid,dp);
        if(answer == INT_MIN) return -1;
        return answer;
    }
};