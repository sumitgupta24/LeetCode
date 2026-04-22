class Solution {
public:
    int editsRequired(string word, string dict) {
        int n = word.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(word[i] != dict[i]) count++;
        }
        return count;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = dictionary.size();
        vector<string> ans;
        for(auto& word : queries) {
            for(auto& dict : dictionary) {
                if(editsRequired(word, dict) <= 2) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};