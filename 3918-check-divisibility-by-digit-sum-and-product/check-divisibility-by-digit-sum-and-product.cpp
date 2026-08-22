class Solution {
public:
    int findDigitProductSum(int n) {
        int temp = n;

        int digitSum = 0;
        int digitProduct = 1;

        while(temp != 0) {
            int digit = temp % 10;

            digitSum += digit;
            digitProduct *= digit;

            temp = temp / 10;
        }

        return digitSum + digitProduct;
    }

    bool checkDivisibility(int n) {
        int sum = findDigitProductSum(n);
        return !(n % sum);
    }
};