class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]].push_back(i);
        int minDist = INT_MAX;
        for(auto& [num,arr]: mpp){
            if(arr.size() >= 3){
                for(int i=0;i<arr.size()-2;i++){
                    int temp = abs(arr[i] - arr[i+1]) + abs(arr[i+1] - arr[i+2]) + abs(arr[i+2] - arr[i]);
                    minDist = min(minDist,temp);
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};