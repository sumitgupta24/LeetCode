class Solution {
public:
    int solve(int i, int gcdA, int gcdB, vector<int>& nums,vector<vector<vector<int>>>& dp) {
        int mod = 1e9 + 7;

        if(i == nums.size()) return (gcdA != 0 && gcdB != 0 && gcdA == gcdB) ? 1 : 0;

        if(dp[i][gcdA][gcdB] != -1) return dp[i][gcdA][gcdB];

        long long takeA = solve(i + 1, gcd(gcdA, nums[i]), gcdB, nums, dp);
        long long takeB = solve(i + 1, gcdA, gcd(gcdB, nums[i]), nums, dp);
        long long skip = solve(i + 1, gcdA, gcdB, nums, dp);

        return dp[i][gcdA][gcdB] = (takeA + takeB + skip) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxElement = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxElement + 1, vector<int>(maxElement + 1, -1)));

        return solve(0, 0, 0, nums, dp);
    }
};