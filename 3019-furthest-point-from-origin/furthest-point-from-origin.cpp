class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int x1 = 0;
        for(int i = 0; i < n; i++) {
            if(moves[i] == 'L' || moves[i] == '_') x1--;
            else x1++;
        }
        int x2 = 0;
        for(int i = 0; i < n; i++) {
            if(moves[i] == 'R' || moves[i] == '_') x2++;
            else x2--;
        }

        return max(abs(x1), abs(x2));
    }
};