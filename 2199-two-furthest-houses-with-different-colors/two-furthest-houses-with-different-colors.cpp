class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = 0;
        int i = 0, j = n - 1;
        while(i < n) {
            if(colors[i] != colors[j]) {
                maxDist = max(maxDist, j - i);
                break;
            }
            else {
                i++;
            }
        }
        i = 0;
        while(j >= 0) {
            if(colors[i] != colors[j]) {
                maxDist = max(maxDist, j - i);
                break;
            }
            else {
                j--;
            }
        }
        return maxDist;
    }
};