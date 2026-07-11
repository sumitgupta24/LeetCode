class Solution {
public:
    pair<int, int> bfs(int i, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;

        int nodeCount = 0;
        int edgeCount = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            nodeCount++;

            for(auto& adjNode: adj[node]) {
                edgeCount++;

                if(!visited[adjNode]) {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }

        edgeCount /= 2;

        return {nodeCount, edgeCount};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                pair<int, int> count = bfs(i, visited, adj);

                int edgeCount = count.second;
                int nodeCount = count.first;

                if(edgeCount == (nodeCount * (nodeCount - 1)) / 2) ans++;
            }
        }

        return ans;
    }
};