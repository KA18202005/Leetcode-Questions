class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            int window = 0;
            for(int j = 0; j <= k; j++) {
                window = (window + dp[i - 1][j]) % MOD;
                if(j >= i) {
                    window = (window - dp[i - 1][j - i] + MOD) % MOD;
                }
                dp[i][j] = window;
            }
        }
        return dp[n][k];
    }
};