class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();

        if(n <= 1) return s;

        vector<int> freq(26, 0);
        for(char& ch: s) freq[ch - 'a']++;

        string str(n, ' ');

        int j = 0, k = n - 1;

        for(int i = 0; i < 26; i++) {
            int count = freq[i];

            if(count % 2 == 1) {
                str[n / 2] = i + 'a';
                count--;
            }

            int half = count / 2;

            while(count != half) {
                str[j++] = i + 'a';
                count--;
            }
            while(count != 0) {
                str[k--] = i + 'a';
                count--;
            }
        }

        return str;
    }
};