class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        set<int> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k || digits[i] == 0) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(num % 2 == 0) st.insert(num);
                }
            }
        }
        for(auto& it : st) cout << it << " ";
        return st.size();
    }
};