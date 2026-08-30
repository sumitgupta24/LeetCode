class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> maxi, mini;

        maxi.first = INT_MIN;
        mini.first = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i] > maxi.first) {
                maxi.first = nums[i];
                maxi.second = i;
            }

            if(nums[i] < mini.first) {
                mini.first = nums[i];
                mini.second = i;
            }
        }

        int case1 = max(mini.second, maxi.second) + 1;
        int case2 = max(n - mini.second, n - maxi.second);
        int case3 = mini.second + n - maxi.second + 1;
        int case4 = maxi.second + n - mini.second + 1;

        return min({case1, case2, case3, case4});
    }
};