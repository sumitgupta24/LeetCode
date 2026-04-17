class Solution {
public:
    int reverseNum(int num){
        string str = to_string(num);
        reverse(str.begin(),str.end());
        return stoi(str);
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int minIndex = INT_MAX;
        for(int i=0;i<n;i++){
            int rev = reverseNum(nums[i]);
            if(mpp.find(nums[i]) != mpp.end()){
                minIndex = min(minIndex,abs(mpp[nums[i]] - i));
            }
            mpp[rev] = i;
        }
        return minIndex == INT_MAX ? -1 : minIndex;
    }
};