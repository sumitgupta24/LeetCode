class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> mpp;
        vector<int> C(n);
        for(int i = 0; i < n; i++) {
            mpp[A[i]]++;
            mpp[B[i]]++;
            int count = 0;
            for(auto& it : mpp) {
                if(it.second == 2) count++;
            }
            C[i] = count;
        }
        return C;
    }
};