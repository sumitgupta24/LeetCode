class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int firstSum = 0, secondSum = 0, firstCount = 0, secondCount = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] != '?') firstSum += num[i] -'0';
            else firstCount++;

            if(num[n - i - 1] != '?') secondSum += num[n - i - 1] - '0';
            else secondCount++;
        }

        int countDiff = firstCount - secondCount;
        int sumDiff = firstSum - secondSum;

        return 2 * sumDiff + 9 * countDiff != 0;
    }
};