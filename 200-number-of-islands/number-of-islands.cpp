class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        queue<pair<int,int>> q;
        q.push({i, j});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int dir=0;dir<4;dir++){
                int nrow = row + drow[dir];
                int ncol = col + dcol[dir];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    bfs(i, j, grid, visited);
                }
            }
        }

        return count;
    }
};