class Solution {
public:
    void rotateString(string& s) {
        int n = s.length();
        char temp = s[0];
        for(int i = 0; i < n - 1; i++) {
            s[i] = s[i + 1];
        }
        s[n - 1] = temp;
    }

    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m) return false;
        int j = n;
        while(j != 0) {
            rotateString(s);
            if(s == goal) return true;
            j--;
        }
        return false;
    }
};