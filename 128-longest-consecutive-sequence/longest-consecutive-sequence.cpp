class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int& num : nums) st.insert(num);

        int maxAns = 0;
        for(int num : st){
            if(st.find(num - 1) == st.end()){
                int curr = num;
                int currAns = 1;
                while(st.find(curr + 1) != st.end()){
                    curr++;
                    currAns++;
                }
                maxAns = max(maxAns, currAns);
            }
        }
        return maxAns;
    }
};