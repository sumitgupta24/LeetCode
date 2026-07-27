class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            } 
            else if(secondLargest < nums[i]) secondLargest = nums[i];
        }

        return (largest - 1) * (secondLargest - 1);
    }
};