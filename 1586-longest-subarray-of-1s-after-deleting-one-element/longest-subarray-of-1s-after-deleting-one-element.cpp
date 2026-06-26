class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0;
        int maxAns = 0;
        int sum = 0;
        bool flag = true;

        while(j < n) {
            if(nums[j] == 0) flag = false;
            sum += nums[j];

            while(sum < j - i) {
                sum -= nums[i];
                i++;
            }

            maxAns = max(maxAns, sum);
            j++;
        }

        return flag ? maxAns - 1 : maxAns;
    }
};