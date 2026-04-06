class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        set<pair<int,int>> st;
        for(auto& it: obstacles){
            st.insert({it[0], it[1]});
        }
        int maxPoint = 0;
        int x = 0, y = 0;
        int dir = 0;
        for(int i=0;i<n;i++){
            if(commands[i] == -2) dir = (dir + 1) % 4;
            else if(commands[i] == -1) dir = ((dir - 1) % 4 + 4) % 4;
            else{
                int k = commands[i];
                if(dir == 0){
                    for(int j=0;j<k;j++){
                        if(!st.count({x, y + 1})) y++;
                    }
                }
                else if(dir == 1){
                    for(int j=0;j<k;j++){
                        if(!st.count({x - 1, y})) x--;
                    }
                }
                else if(dir == 2){
                    for(int j=0;j<k;j++){
                        if(!st.count({x, y - 1})) y--;
                    }
                }
                else if(dir == 3){
                    for(int j=0;j<k;j++){
                        if(!st.count({x + 1, y})) x++;
                    }
                }
            }
            maxPoint = max(maxPoint, x * x + y * y);
        }
        return maxPoint;
    }
};