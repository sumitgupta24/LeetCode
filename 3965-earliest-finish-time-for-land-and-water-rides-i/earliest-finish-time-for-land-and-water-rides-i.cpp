class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int minTime = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int t1 = landStartTime[i] + landDuration[i];
                if(t1 <= waterStartTime[j]) t1 += waterStartTime[j] - t1 + waterDuration[j];
                else t1 += waterDuration[j];
                minTime = min(minTime, t1);
                int t2 = waterStartTime[j] + waterDuration[j];
                if(t2 <= landStartTime[i]) t2 += landStartTime[i] - t2 + landDuration[i];
                else t2 += landDuration[i];
                minTime = min(minTime, t2);
            }
        }

        return minTime;
    }
};