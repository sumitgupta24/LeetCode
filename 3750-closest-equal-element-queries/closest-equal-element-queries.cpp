class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int q : queries) {
            auto& indexArray = mpp[nums[q]];
            int m = indexArray.size();

            if(m <= 1) {
                ans.push_back(-1);
                continue;
            }

            int ind = lower_bound(indexArray.begin(), indexArray.end(), q) - indexArray.begin();

            int prev = indexArray[(ind - 1 + m) % m];
            int next = indexArray[(ind + 1) % m];

            int l = abs(q - prev);
            int r = abs(next - q);

            l = min(l, n - l);
            r = min(r, n - r);

            ans.push_back(min(l, r));
        }

        return ans;
    }
};