class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, int> lower, upper;

        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(islower(ch)) lower[ch] = i;
        }

        set<char> st;

        for(int i = 0; i < n; i++) {
            if(isupper(word[i])) {
                int ind = i;
                if(upper.find(word[i]) == upper.end()) upper[word[i]] = i; 
                else ind = upper[word[i]];
                char ch = tolower(word[i]);
                if(lower.find(ch) != lower.end() && lower[ch] < ind) st.insert(ch); 
            }
        }

        return st.size();
    }
};