class Robot {
public:
    int n, m;
    int x = 0, y = 0;
    int dir = 3;
    Robot(int width, int height) {
        n = width;
        m = height;
    }
    
    void step(int num) {
        int perimeter = 2 * (n + m - 2);
        int k = num % perimeter;
        if(k == 0) k = perimeter;
        while(k != 0){
            if(dir == 0){
                if(y + 1 < m){
                    y++;
                    k--;
                } 
                else  dir = 1;
            }
            else if(dir == 1){
                if(x - 1 >= 0){
                    x--;
                    k--;
                } 
                else dir = 2;
            }
            else if(dir == 2){
                if(y - 1 >= 0){
                    y--;
                    k--;
                } 
                else dir = 3;
            }
            else if(dir == 3){
                if(x + 1 < n){
                    x++;
                    k--;
                }
                else dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir == 0) return "North";
        else if(dir == 1) return "West";
        else if(dir == 2) return "South";
        else return "East";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */