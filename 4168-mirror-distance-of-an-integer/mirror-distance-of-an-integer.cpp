class Solution {
public:
    int reverseInteger(int n){
        string str = to_string(n);
        reverse(str.begin(),str.end());
        return stoi(str);
    }
    
    int mirrorDistance(int n) {
        return abs(n - reverseInteger(n));
    }
};