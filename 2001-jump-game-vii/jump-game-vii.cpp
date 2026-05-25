class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> visited(n, false);
        visited[0] = true;

        int farthest = 0;

        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int ind = q.front();
            q.pop();
            if(ind == n - 1) return true;

            int start = max(ind + minJump, farthest + 1);
            int end = min(ind + maxJump, n - 1);

            for(int i = start; i <= end; i++) {
                if(s[i] == '0' && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
            farthest = end;
        }
        return false;
    }
};