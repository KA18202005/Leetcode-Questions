class Solution {
    int digit(int n) {
        int prod = 1;
        while(n != 0) {
            int d = n % 10;
            prod *= d;
            n = n / 10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        while(n) {
            int prod = digit(n);
            if(prod % t == 0) return n;
            else n++;
        }
        return -1;
    }
};