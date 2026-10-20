class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board, char ch, int n) {
        int m = sqrt(n);
    
        for(int i = 0; i < n; i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[m * (row / m) + i / m][m * (col / m) + i % m] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    for(char ch = '1'; ch <= '0' + n; ch++) {
                        if(isValid(i, j, board, ch, n)) {
                            board[i][j] = ch;
                            if(solve(board, n)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n);
    }
};