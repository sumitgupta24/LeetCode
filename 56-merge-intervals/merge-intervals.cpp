class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;

        int i = 0;

        while(i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;

            while(j < n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);
                j++;
            }

            ans.push_back({start, end});
            i = j;
        }

        return ans;
    }
};