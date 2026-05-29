class Solution {
public:
    int sumOfNum(int num) {
        int sum = 0;
        while(num != 0) { 
            int digit = num % 10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int n = nums.size();

        int minSum = INT_MAX;

        for(int i = 0; i < n; i++) {
            int sum = sumOfNum(nums[i]);
            minSum = min(minSum, sum);
        }

        return minSum;
    }
};