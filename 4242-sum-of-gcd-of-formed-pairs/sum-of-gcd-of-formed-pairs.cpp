class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd(n);

        int maxi = nums[0];
        prefixGcd[0] = nums[0];

        for(int i = 1; i < n; i++) {
            maxi = max(maxi, nums[i]);
            int val = gcd(nums[i], maxi);
            prefixGcd[i] = val;
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = n - 1;
        long long sum = 0;

        while(i < j) {
            int val = gcd(prefixGcd[i], prefixGcd[j]);
            sum += val;
            i++;
            j--;
        }

        return sum;
    }
};