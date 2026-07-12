class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n =  arr.size();

        set<int> st(arr.begin(), arr.end());
        int rank = 1;
        unordered_map<int, int> mpp;

        for(auto& it: st) {
            mpp[it] = rank;
            rank++;
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++) ans[i] = mpp[arr[i]];

        return ans;
    }
};