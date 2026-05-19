class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(nums1[i]);
        }
        for(auto& it : nums2) {
            if(st.count(it)) return it;
        }
        return -1;
    }
};