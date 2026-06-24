class Solution {
public:
    const int MOD=1e9+7;
    
    vector<vector<long long>> matmul(vector<vector<long long>>&a, vector<vector<long long>>b) {
        int n = a.size(); 
        int m = a[0].size();
        int p = b[0].size();
        vector<vector<long long>> c(n, vector<long long>(p, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < p; j++) {
                for(int k = 0; k < m; k++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return c;
    }

    vector<vector<long long>> p(vector<vector<long long>>&a, int b) {
        int n = a.size();
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for(int i = 0; i < n; i++) ans[i][i] = 1;
        while(b) {
            if(b & 1) ans = matmul(ans, a);
            a = matmul(a,a);
            b /= 2;
        }

        return ans;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<vector<long long>> a(2 * m, vector<long long>(2 * m, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++) a[i][j + m] = 1;
            for(int j = i + 1; j < m; j++) a[i + m][j] = 1;
        }

        a = p(a, n - 1);
        long long ans = 0;
        for(int i = 0; i < 2 * m; i++) {
            for(int j = 0; j < 2 * m; j++) {
                ans = (ans + a[i][j]) % MOD;
            }
        }
        
        return (int)(ans);
    }
};