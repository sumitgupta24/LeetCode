class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        bool hasAtleastOneNonZero = false;

        for(int i = 0; i < n; i++) {
            xorr ^= nums[i];
            if(nums[i] != 0) hasAtleastOneNonZero = true;
        }

        if(xorr != 0) return n;
        return hasAtleastOneNonZero ? n - 1  : 0;  
    }
};