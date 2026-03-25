class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j=1;j<m;j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        long long totalSum = dp[n-1][m-1];
        for(int i=0;i<n;i++){
            long long sum = totalSum - dp[i][m-1];
            if(sum == dp[i][m-1]) return true; 
        }
        for(int j=0;j<m;j++){
            long long sum = totalSum - dp[n-1][j];
            if(sum == dp[n-1][j]) return true; 
        }
        return false;
    }
};