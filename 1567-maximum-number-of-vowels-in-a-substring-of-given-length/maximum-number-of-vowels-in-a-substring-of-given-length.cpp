class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();

        int maxCount = 0;

        for(int i = 0; i < k; i++) if(isVowel(s[i])) maxCount++;

        int count = maxCount;

        for(int i = k; i < n; i++) {
            if(isVowel(s[i])) count++;
            if(isVowel(s[i - k])) count--;

            maxCount = max(maxCount, count);
        }
       
        return maxCount;
    }
};