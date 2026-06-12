class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<vector<int>> up;
    vector<int> depth;

    const int MOD = 1e9 + 7;
    using ll = long long;

    ll modPow(ll a, ll b) {
        if (b == 0) return 1;

        ll half = modPow(a, b / 2) % MOD;
        ll res = (half * half) % MOD;

        if (b & 1) {
            res = (res * a) % MOD;
        }

        return res;
    }

    void build(int node, int parent, int dep) {
        depth[node] = dep;
        up[node][0] = parent;

        for (int i = 1; i < 18; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int child : graph[node]) {
            if (child == parent) continue;
            build(child, node, dep + 1);
        }
    }

    int kthParent(int node, int k) {
        int bit = 0;

        while (k) {
            if (k & 1) {
                node = up[node][bit];
            }
            k >>= 1;
            bit++;
        }

        return node;
    }

    int lca(int a, int b) {
        if (depth[b] > depth[a]) {
            swap(a, b);
        }

        a = kthParent(a, depth[a] - depth[b]);

        if (a == b) return a;

        for (int i = 17; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {

        for (auto &e : edges) {
            int a = e[0];
            int b = e[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int n = edges.size() + 1;

        up.resize(n + 1, vector<int>(18, 0));
        depth.resize(n + 1, 0);

        build(1, 0, 0);

        vector<int> ans;

        for (auto &q : queries) {
            int a = q[0];
            int b = q[1];

            int p = lca(a, b);

            if (a == b) {
                ans.push_back(0);
            }
            else if (p == a || p == b) {

                int dist = abs(depth[a] - depth[b]);

                ans.push_back(modPow(2, dist - 1));
            }
            else {
                int d1 = depth[a] - depth[p];
                int d2 = depth[b] - depth[p];

                ll x = modPow(2, d1 - 1);
                ll y = modPow(2, d2 - 1);

                ans.push_back((2LL * x % MOD * y) % MOD);
            }
        }
        return ans;
    }
};