class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int num = nums[n - 1];

        if(num != n - 1) return false;

        for(int i = 1; i < n; i++) {
            if(i != nums[i - 1]) return false;
        }
        return nums[n - 1] == num;
    }
};