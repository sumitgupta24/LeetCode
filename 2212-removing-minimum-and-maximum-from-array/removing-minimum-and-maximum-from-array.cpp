class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[maxIndex]) maxIndex = i;
            if(nums[i] < nums[minIndex]) minIndex = i;
        }

        int case1 = max(maxIndex, minIndex) + 1;
        int case2 = max(n - minIndex, n - maxIndex);
        int case3 = minIndex + 1 + n - maxIndex;
        int case4 = maxIndex + 1 + n - minIndex;

        return min({case1, case2, case3, case4});
    }
};