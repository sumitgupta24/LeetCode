class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<long long, bool> Map;
        for (int i = 0; i < arr1.size(); i++){
            while (arr1[i]){
                Map[arr1[i]] = true;
                arr1[i] /= 10;
            }
        }
        long long ans = 0;
        for (int i = 0; i < arr2.size(); i++){
            while (arr2[i]){
                if (Map[arr2[i]]){
                    long long num = arr2[i];
                    long long len = 0;
                    while (num){
                        len++;
                        num /= 10;
                    }
                    ans = max(ans, len);
                }
                arr2[i] /= 10;
            }
        }
        return ans;
    }
};