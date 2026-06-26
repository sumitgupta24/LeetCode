class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> mpp;

        int i = 0, j = 0;
        int maxFruit = 0;

        while(j < n) {
            mpp[fruits[j]]++;

            if(mpp.size() > 2) {
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            
            maxFruit = max(maxFruit, j - i + 1);
            j++;
        }

        return maxFruit;
    }
};