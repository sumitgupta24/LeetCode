class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        int N = s.length();
        vector<int> C(N + 1, 0); 
        vector<long long> prefixSum(N + 1, 0); 
        vector<long long> prefixVal(N + 1, 0); 
        vector<long long> powersOf10(N + 1, 1); 
        for (int i = 1; i <= N; ++i) {
            powersOf10[i] = (powersOf10[i - 1] * 10) % mod;
            
            int digit = s[i - 1] - '0';
            
            prefixSum[i] = prefixSum[i - 1];
            prefixVal[i] = prefixVal[i - 1];
            C[i] = C[i - 1];
            
            if (digit != 0) {
                prefixSum[i] = (prefixSum[i] + digit) % mod;
                C[i]++;
                prefixVal[i] = (prefixVal[i-1] * 10 + digit) % mod;
            }
        }
        vector<int> answers;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            long long sRaw = prefixSum[r + 1] - prefixSum[l];
            long long s = (sRaw % mod + mod) % mod;
            int length = C[r + 1] - C[l];

            if (length == 0) {
                answers.push_back(0);
                continue;
            }
            long long scaleFactor = powersOf10[length];
            long long xScaledPrefix = (prefixVal[l] * scaleFactor) % mod;
            long long xRaw = prefixVal[r + 1] - xScaledPrefix;
            long long x = (xRaw % mod + mod) % mod; 
            
            long long result = (x * s) % mod;
            answers.push_back((int)result);
        }

        return answers;
    }
};