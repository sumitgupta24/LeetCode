class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp = mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nj = (j + m + k) % m;
                if(mat[i][j] != mat[i][nj]) return false;
            }
        }
        return true;
    }
};