class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> mpp;

        for(auto& str: knowledge) mpp[str[0]] = str[1];

        int i = 0;
        string ans = "";

        while(i < n) {
            if(s[i] == '(') {
                i++;
                string key = "";
                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if(mpp.find(key) != mpp.end()) ans += mpp[key];
                else ans += '?';
            }
            if(s[i] != ')') ans += s[i];
            i++;
        }

        return ans;
    }
};