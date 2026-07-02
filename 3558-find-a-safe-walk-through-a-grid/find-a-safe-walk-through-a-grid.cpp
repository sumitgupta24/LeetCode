class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        health -= grid[0][0];
        if(health <= 0) return false;

        vector<vector<int>> best(n, vector<int>(m, -1));
        queue<vector<int>> q;

        q.push({0, 0, health});
        best[0][0] = health;

        int di[] = {-1, 0, 1, 0};
        int dj[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            int i = curr[0];
            int j = curr[1];
            int currHealth = curr[2];

            if(i == n - 1 && j == m - 1) return true;

            for(int dir = 0; dir < 4; dir++) {
                int newI = i + di[dir];
                int newJ = j + dj[dir];

                if(newI >= 0 && newJ >= 0 && newI < n && newJ < m) {
                    int newHealth = currHealth - grid[newI][newJ];

                    if(newHealth <= 0) continue;

                    if(newHealth > best[newI][newJ]) {
                        best[newI][newJ] = newHealth;
                        q.push({newI, newJ, newHealth});
                    }
                }
            }
        }

        return false;
    }
};