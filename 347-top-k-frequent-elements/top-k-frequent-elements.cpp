class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) mpp[nums[i]]++;

        priority_queue<pair<int, int>> pq;
        for(auto& [num, count] : mpp) pq.push({count, num});

        vector<int> ans;

        while(k != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};