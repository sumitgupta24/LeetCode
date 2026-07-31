class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++) mpp[word[i] - 'a']++;

        vector<pair<int, int>> freq;

        for(auto& [ch, count] : mpp) freq.push_back({ch, count});

        sort(freq.begin(), freq.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });

        int sz = freq.size();

        int count = 0;

        for(int i = 0; i < sz; i++) {
            if(i < 8) count += freq[i].second;
            else if(i < 16)  count += 2 * freq[i].second;
            else if(i < 24) count += 3 * freq[i].second;
            else count += 4 * freq[i].second;
        }

        return count;
    }
};