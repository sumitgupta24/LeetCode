class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        vector<int> freq(26, 0);
        for(char& ch: s) freq[ch - 'a']++;

        vector<bool> visited(26, 0);

        string ans = "";

        for(char& ch: s) {
            freq[ch - 'a']--;

            if(visited[ch - 'a']) continue;

            while(!ans.empty() && ans.back() > ch && freq[ans.back() - 'a'] > 0) {
                visited[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans += ch;
            visited[ch - 'a'] = 1;
        }

        return ans;
    }
};