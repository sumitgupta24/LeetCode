class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> tempNums = nums;
        sort(tempNums.begin(), tempNums.end());

        int k = n;
        while(k != 0) {
            int temp = nums[0];
            for(int i = 0; i < n - 1; i++) {
                nums[i] = nums[i + 1];
            }
            nums[n - 1] = temp;
            if(nums == tempNums) return true;
            k--;
        }
        return false;
    }
};