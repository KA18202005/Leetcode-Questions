class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        double ans = 1;
        if(n < 0) {
            m = -m;
        }
        while( m > 0) {
            if(m % 2 == 1) {
                ans = ans * x;
                m--;
            }
            else {
                m = m / 2;
                x = x * x;
            }
        }
        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};