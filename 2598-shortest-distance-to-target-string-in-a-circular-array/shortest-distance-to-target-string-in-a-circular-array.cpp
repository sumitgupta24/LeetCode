class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = n;
        for(int i=0;i<n;i++){
            if(words[i] == target){
                minDist = min({minDist, abs(i - startIndex), (n - abs(i - startIndex))});
            }
        }
        return minDist == n ? -1 : minDist;
    }
};