class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0;
        int high = n-1;
        int minVal = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                minVal = min(minVal,nums[low]);
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[high]){
                minVal = min(minVal,nums[low]);
                // break;
            }
            if(nums[low]<=nums[mid]){
                minVal = min(minVal,nums[low]);
                low = mid+1;
            }
            else{
                minVal = min(minVal,nums[mid]);
                high = mid-1;
            }
        }
        return minVal;
    }
};