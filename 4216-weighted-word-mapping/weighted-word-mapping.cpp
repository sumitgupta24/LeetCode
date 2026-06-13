class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";
        
        for(string& str : words) {
            int weight = 0;
            for(char& ch : str) {
                weight += weights[ch - 'a'];
            }
            weight = weight % 26;
            weight = 25 - weight;
            ans += (weight + 'a');
        }

        return ans;
    }
};