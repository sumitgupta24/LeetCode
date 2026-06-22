class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for(char& ch: text) {
            b += ch == 'b';
            a += ch == 'a';
            l += ch == 'l';
            o += ch == 'o';
            n += ch == 'n';
        }

        int single = min({b, a, n});
        int doub = min(l, o) / 2;;

        return min(single, doub);
    }
};