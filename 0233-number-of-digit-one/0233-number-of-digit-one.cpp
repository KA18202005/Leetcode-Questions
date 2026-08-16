class Solution {
public:
    int countDigitOne(int n) {
        long long ones = 0;    
        for (long long m = 1; m <= n; m *= 10) {
            long long higher = n / (m * 10);
            long long current = (n / m) % 10;
            long long lower = n % m;
            if (current == 0) {
                ones += higher * m;
            }
            else if (current == 1) {
                ones += higher * m + lower + 1;
            }
            else {
                ones += (higher + 1) * m;
            }
        }
        return ones;
    }
};