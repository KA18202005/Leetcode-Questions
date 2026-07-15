class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, even = 0;
        for(int i = 0; i < 2 * n; i++) {
            odd += i + 1;
            even += i + 2;
        }
        return gcd(odd, even);
    }
};