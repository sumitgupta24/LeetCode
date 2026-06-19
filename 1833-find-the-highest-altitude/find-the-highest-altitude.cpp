class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int maxAltitude = 0;
        int totalAltitude = 0;

        for(int i = 0; i < n; i++) {
            totalAltitude += gain[i];
            maxAltitude = max(maxAltitude, totalAltitude);
        }
        maxAltitude = max(maxAltitude, totalAltitude);
        return maxAltitude;
    }
};