class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    // visited[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        int count = 0;
        int di[] = {-1,0,1,0};
        int dj[] = {0,-1,0,1};
        while(!q.empty()){
            int i = q.front().second.first;
            int j = q.front().second.second;
            int steps = q.front().first;
            q.pop();
            count = max(count, steps);
            for(int dir=0;dir<4;dir++){
                int ni = i + di[dir];
                int nj = j + dj[dir];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1){
                    grid[ni][nj] = 2;
                    q.push({steps + 1, {ni, nj}});
                    // visited[ni][nj] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1; 
            }
        }
        return count;
    }
};