class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);

        int m = str.length();
        string temp = "";

        long long sum = 0;

        for(int i = 0; i < m; i++) {
            if(str[i] != '0') temp += str[i];
            sum += (str[i] - '0');
        }
        
        if(temp.empty()) return 0;
        return stoll(temp) * sum ;
    }
};