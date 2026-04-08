class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        int n = nums.size();
        for(auto& it : queries){
            int l = it[0], r = it[1];
            int k = it[2], v = it[3];
            for(int i=l;i<=r;i+=k){
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }
        int xorr = 0;
        for(int i=0;i<n;i++){
            xorr ^= nums[i];
        }
        return xorr;
    }
};