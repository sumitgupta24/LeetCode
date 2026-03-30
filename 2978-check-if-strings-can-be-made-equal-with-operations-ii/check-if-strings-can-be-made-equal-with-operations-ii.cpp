class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        vector<int> freq(52,0);
        for(int i=0;i<n;i++){
            int pos = (i & 1) * 26;
            freq[s1[i] - 'a' + pos]++;
            freq[s2[i] - 'a' + pos]--;
        }
        for(int i=0;i<52;i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};