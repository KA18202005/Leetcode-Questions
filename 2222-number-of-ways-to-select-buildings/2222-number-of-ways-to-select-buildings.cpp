class Solution {
public:
    long long numberOfWays(string s) {
        long long dp[4][2] = {};
        for (char c : s) {
            int x = c - '0';
            for (int j = 3; j >= 1; j--) {
                dp[j][x] += dp[j - 1][1 - x];
                if (j == 1) dp[j][x]++;
            }
        }
        return dp[3][0] + dp[3][1];
    }
};