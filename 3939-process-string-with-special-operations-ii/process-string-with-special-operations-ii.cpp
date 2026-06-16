class Solution {
public:
    char processStr(string s, long long k) {
        long long n = 0;

        for(char& ch : s) {
            if(islower(ch)) n++;
            else if(ch == '#') n *= 2;
            else if(ch == '*' && n > 0) n--;
        }
        if(k >= n) return '.';
        for(int i = s.size() - 1; i >= 0; i--) {
            if(islower(s[i])) {
                n--;
                if(n == k) return s[i];
            }
            else if(s[i] == '#') {
                n /= 2;
                if(k >= n) k -= n;
            }
            else if(s[i] == '%') k = n - k - 1;
            else if(s[i] == '*' && n > 0) n++;
        }

        return '.';
    }
};