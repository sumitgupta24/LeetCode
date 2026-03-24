class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size();
        int m = grid[0].size();
        int k = n * m;
        vector<long long> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }
        vector<long long> prefix(k, 1);
        vector<long long> suffix(k, 1);
        prefix[0] = arr[0];
        suffix[k-1] = arr[k-1];
        for(int i=1;i<k;i++) prefix[i] = (1LL * prefix[i-1] * arr[i]) % mod;
        for(int i=k-2;i>=0;i--) suffix[i] = (1LL * suffix[i+1] * arr[i]) % mod;

        arr[0] = suffix[1] % mod;
        arr[k-1] = prefix[k-2] % mod;

        for(int i=1;i<k-1;i++) arr[i] = (1LL * prefix[i-1] * suffix[i+1]) % mod;
        for(int i=0;i<k;i++) grid[i/m][i%m] = arr[i];
        
        return grid;
    }
};