class Solution {
public:
    bool canCommunicate(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {
            if(i == row) continue;
            if(grid[i][col] == 1) return true; 
        }

        for(int j = 0; j < m; j++) {
            if(j == col) continue;
            if(grid[row][j] == 1) return true;
        }

        return false;
    }

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    if(canCommunicate(grid, i, j)) count++;
                }
            }
        }

        return count;

        // int count = 0;
        // vector<vector<bool>> visited(n, vector<bool>(m, false));

        // queue<pair<int, int>> q;

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         if(grid[i][j] == 1) {
        //             q.push({i, j});
        //             visited[i][j] = true;
        //         }
        //     }
        // }

        // while(!q.empty()) {
        //     int i = q.front().first;
        //     int j = q.front().second;

        //     q.pop();


        // }
    }
};