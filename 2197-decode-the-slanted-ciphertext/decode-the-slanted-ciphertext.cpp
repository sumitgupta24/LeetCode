class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        int n = rows;
        int m = len / rows;
        vector<vector<char>> grid(n, vector<char>(m, ' '));
        for(int i=0;i<len;i++){
            grid[i/m][i%m] = encodedText[i];
        };
        string str = "";
        for(int k=0;k<m;k++){
            int i = 0, j = k;
            while(i < n && j < m){
                str += grid[i][j];
                i++;
                j++;
            }
        }
        while(!str.empty() && str.back() == ' ') str.pop_back();
        return str;
    }
};