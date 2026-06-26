class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int i = 0;

        while(i <= n) {
            int end = intervals[i][1];

            int j = i + 1;
            while(j <= n && end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);
                j++;
            }

            ans.push_back({intervals[i][0], end});
            i = j;
        }

        return ans;
    }
};