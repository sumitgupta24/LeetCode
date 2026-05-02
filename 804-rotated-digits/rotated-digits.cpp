class Solution {
public:
    int rotatedDigits(int n) {
       unordered_set<int>invalid = {3, 4, 7};
       unordered_set<int>contribute = {2, 5, 6, 9};
       int count = 0;
       for(int i = 1; i <= n; i++) {
            int number = i;
            bool isValid = false;
            while(number) {
                int digit = number%10;
                if(invalid.find(digit) != invalid.end()) {
                    isValid = false;
                    break;
                }
                if(contribute.find(digit) != contribute.end()) {
                    isValid = true;
                }
                number /= 10;
            }
            if(isValid) {
                count++;
            }
       }
       return count;
    }
};