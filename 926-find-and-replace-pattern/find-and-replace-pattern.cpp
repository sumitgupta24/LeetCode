class Solution {
public:
    string findNumericPattern(string word) {
        int n = word.size();

        string numericPattern = "";

        unordered_map<char, int> mpp;
        int index = 0;

        for(int i = 0; i < n; i++) {
            if(mpp.find(word[i]) == mpp.end()) {
                index++;
                mpp[word[i]] = index;
            }
            numericPattern += to_string(mpp[word[i]]);
            numericPattern += "_";
        }

        return numericPattern;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();

        string numericPattern = findNumericPattern(pattern);
        // cout << numericPattern << " ";

        vector<string> ans;

        for(int i = 0; i < n; i++) {
            string currNumericPattern = findNumericPattern(words[i]);
            // cout << currNumericPattern << " ";
            if(numericPattern == currNumericPattern) ans.push_back(words[i]);
        }

        return ans;
    }
};