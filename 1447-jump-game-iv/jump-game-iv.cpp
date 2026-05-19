class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> temp;
        for(int i=0;i<n;i++){
            temp[arr[i]].push_back(i);
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(i+1<n) adj[i].push_back(i+1);
            if(i-1>=0) adj[i].push_back(i-1);
            // for(int j: temp[arr[i]]){
            //     if(j!=i) adj[i].push_back(j);
            // }
        }
        vector<int> visited(n,0);
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0] = 1;
        while(!q.empty()){
            int i = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(i==n-1) return steps;
            for(auto it: adj[i]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push({it,steps+1});
                }
            }
            if(temp.count(arr[i])){
                for(int j: temp[arr[i]]){
                    if(!visited[j]){
                        visited[j] = 1;
                        q.push({j,steps+1});
                    }
                }
                temp.erase(arr[i]);
            }
        }
        return -1;
    }
};