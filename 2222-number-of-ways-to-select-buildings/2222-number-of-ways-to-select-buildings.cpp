class Solution {
public:
    long long numberOfWays(string s) {
        long long cnt0 = 0;
        long long cnt1 = 0;
        long long cnt01 = 0;
        long long cnt10 = 0;
        long long cnt010 = 0;
        long long cnt101 = 0;
        for (char c : s) {
            if (c == '0') {
                cnt010 += cnt01;
                cnt10 += cnt1;
                cnt0++;
            }
            else {
                cnt101 += cnt10;
                cnt01 += cnt0;
                cnt1++;
            }
        }
        return cnt010 + cnt101;
    }
};