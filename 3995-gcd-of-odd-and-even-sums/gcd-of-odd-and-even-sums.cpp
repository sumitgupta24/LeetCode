class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOfOdd = n * n;
        int sumOfEven = sumOfOdd + n;

        return gcd(sumOfOdd, sumOfEven);
    }
};