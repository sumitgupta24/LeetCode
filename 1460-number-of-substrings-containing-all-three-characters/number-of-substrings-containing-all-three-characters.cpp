class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int count = 0;
        int a = 0, b = 0, c = 0;

        int i = 0, j = 0;

        while(j < n) {
            a += (s[j] == 'a');
            b += (s[j] == 'b');
            c += (s[j] == 'c');

            while(a && b && c) {
                a -= (s[i] == 'a');
                b -= (s[i] == 'b');
                c -= (s[i] == 'c');
                count += n - j;
                i++;
            }

            j++;
        }

        return count;
    }
};