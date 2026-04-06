class Solution {
public:
    void dfs(int node, int n, vector<vector<int>>& graph,vector<int>& temp, vector<vector<int>>& ans){
        temp.push_back(node);
        if(node == n - 1) ans.push_back(temp);
        for(auto& adjNode : graph[node]){
            dfs(adjNode, n, graph, temp, ans);
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(0, n, graph, temp, ans);
        return ans;
    }
};