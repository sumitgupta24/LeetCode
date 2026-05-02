class Solution {
public:

    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, func = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            func += i * nums[i];
        }
        int maxAns = func;

        for(int i = 0; i < n - 1; i++) {
            int currVal = func + sum - n * nums[n - 1 - i];
            maxAns = max(maxAns, currVal);
            func = currVal;
        }

        return maxAns;
    }
};