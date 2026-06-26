class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int currDiff = abs(sum - target);
                if(minDiff > currDiff) {
                    minDiff = currDiff;
                    ans = sum;
                }
                if(sum < target) j++;
                else k--;
            }
        }

        return ans;
    }
};