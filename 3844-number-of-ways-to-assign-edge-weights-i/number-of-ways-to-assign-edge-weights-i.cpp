class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void dfs(int node, int parent, int depth, vector<vector<int>>& adj, int& maxDepth) {
        maxDepth = max(maxDepth, depth);

        for (int nei : adj[node]) {
            if (nei != parent) {
                dfs(nei, node, depth + 1, adj, maxDepth);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDepth = 0;
        dfs(1, 0, 0, adj, maxDepth);

        return modPow(2, maxDepth - 1);
    }
};