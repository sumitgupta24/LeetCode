class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr;
        int rem = grid[0][0]%x;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]%x!=rem) return -1;
                int temp = grid[i][j];
                arr.push_back(temp);
            }
        }
        sort(arr.begin(),arr.end());
        int k = arr.size();
        int val = arr[k/2];
        int count = 0;
        for(int i=0;i<k;i++){
            if(arr[i]==val) continue;
            int tp = abs(arr[i]-val);
            count += tp/x;
        }
        return count;
    }
};