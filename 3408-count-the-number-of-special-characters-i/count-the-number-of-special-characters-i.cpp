class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26, 0), upper(26, 0);

        for(char& ch : word) {
            if(isupper(ch)) upper[ch - 'A']++;
            else lower[ch - 'a']++;
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {
            if(lower[i] > 0 && upper[i] > 0) count++;
        }

        return count;
    }
};