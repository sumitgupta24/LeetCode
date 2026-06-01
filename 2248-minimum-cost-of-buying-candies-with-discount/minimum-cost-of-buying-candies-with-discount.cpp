class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());

        if(n == 1) return cost[0];
        if(n == 2) return cost[0] + cost[1];
        int ans = 0;
        int i = 1;
        while(i <= n) {
            if(i % 3 == 0) {
                i++;
                continue;
            }
            ans += cost[n - i];
            i++;
        } 
        return ans;
    }
};