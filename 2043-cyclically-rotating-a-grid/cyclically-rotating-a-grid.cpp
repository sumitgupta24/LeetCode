class Solution {
public:
    void fillAgain(int row, int col, vector<vector<int>>& grid, vector<int>& arr) {
        int n = grid.size();
        int m = grid[0].size();

        int p = 0;

        for(int i = row; i < n - row; i++) grid[i][col] = arr[p++];
        for(int j = col + 1; j < m - col; j++) grid[n - row - 1][j] = arr[p++];
        for(int i = n - row - 2; i >= row; i--) grid[i][m - col - 1] = arr[p++];
        for(int j = m - col - 2; j > col; j--) grid[row][j] = arr[p++];

    }

    vector<int> getArray(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;

        for(int i = row; i < n - row; i++) arr.push_back(grid[i][col]);
        for(int j = col + 1; j < m - col; j++) arr.push_back(grid[n - row - 1][j]);
        for(int i = n - row - 2; i >= row; i--) arr.push_back(grid[i][m - col - 1]);
        for(int j = m - col - 2; j > col; j--) arr.push_back(grid[row][j]);

        return arr;
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < min(n, m) / 2; i++) {
            vector<int> arr = getArray(i, i, grid);
            int size = arr.size();
            int temp = k;
            temp = temp % size;
            reverse(arr.begin(), arr.end());
            reverse(arr.begin(), arr.begin() + temp);
            reverse(arr.begin() + temp, arr.end());
            fillAgain(i, i, grid, arr);
        }
        
        return grid;
    }
};