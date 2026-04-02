class Solution {
public:
    int solve(int i, int j, int count, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp){
        int n = coins.size();
        int m = coins[0].size();
        if(i >= n || j >= m) return INT_MIN;
        if(dp[i][j][count] != -1e9) return dp[i][j][count];
        if(i == n - 1 && j == m - 1){
            if(coins[i][j] < 0 && count > 0) return 0;
            return coins[i][j];
        }
        int ans = INT_MIN;

        int right = solve(i, j + 1, count, coins, dp);
        if(right != INT_MIN) right += coins[i][j];

        int down = solve(i + 1, j, count, coins, dp);
        if(down != INT_MIN) down += coins[i][j];

        ans = max(right, down);

        if(coins[i][j] < 0 && count > 0){
            int right2 = solve(i, j + 1, count - 1, coins, dp);
            int down2  = solve(i + 1, j, count - 1, coins, dp);
            ans = max(ans, max(right2, down2));
        }
        return dp[i][j][count] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        return solve(0, 0, 2, coins, dp);
    }
};