class Solution {
public:
    int calculateWaviness(int num) {
        string str = to_string(num);
        int n = str.size();

        int count = 0;
        
        for(int i = 1; i < n - 1; i++) {
            if(str[i] > str[i - 1] && str[i] > str[i + 1]) count++;
            else if(str[i] < str[i - 1] && str[i] < str[i + 1]) count++;
        }

        return count;
    }

    int totalWaviness(int num1, int num2) {
        int countOfWaviness = 0;

        for(int i = num1; i <= num2; i++) {
            int count = calculateWaviness(i);
            countOfWaviness += count;
        }

        return countOfWaviness;
    }
};