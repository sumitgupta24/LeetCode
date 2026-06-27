class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        map<long long, int> mpp;
        for(int num : nums) mpp[num]++;

        int maxLen = 1;

        if(mpp.count(1)) {
            int countOfOne= mpp[1];
            maxLen = max(maxLen, countOfOne % 2 ? countOfOne : countOfOne - 1);
        }

        for(auto& [num, count] : mpp) {
            if(num == 1) continue;

            long long x = num;
            int len = 0;

            while(mpp.count(x) && mpp[x] >= 2) {
                len += 2;
                if(x > 1e9) break;
                x = x * x;
            }

            if(mpp.count(x)) len++;
            else len--;

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};