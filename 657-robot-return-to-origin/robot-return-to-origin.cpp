class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.length();
        int row = 0, col = 0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'U') row--;
            else if(moves[i] == 'D') row++;
            else if(moves[i] == 'L') col--;
            else if(moves[i] == 'R') col++;
        }
        return row == 0 && col == 0;
    }
};