class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1e9 + 7;
        long long dp[2][3] = {};
        dp[0][0] = 1;
        for(int day = 0; day < n; day++) {
            long long next[2][3] = {};
            for(int a = 0; a <= 1; a++) {
                for(int l = 0; l <= 2; l++) {
                    long long ways = dp[a][l];
                    next[a][0] = (next[a][0] + ways) % MOD;
                    if(a == 0) {
                        next[1][0] = (next[1][0] + ways) % MOD;
                    }
                    if(l < 2) {
                        next[a][l + 1] = (next[a][l + 1] + ways) % MOD;
                    }
                }
            }
            for(int a = 0; a <= 1; a++) {
                for(int l = 0; l <= 2; l++) {
                    dp[a][l] = next[a][l];
                }
            }
        }
        long long ans = 0;
        for(int a = 0; a <= 1; a++) {
            for(int l = 0; l <= 2; l++) {
                ans = (ans + dp[a][l]) % MOD;
            }
        }
        return ans;
    }
};