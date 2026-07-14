class Solution {
    static const int mod = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(201, vector<int>(201, 0)));
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            for(int g1 = 0; g1 <= 200; g1++) {
                for(int g2 = 0; g2 <= 200; g2++) {
                    if(dp[i][g1][g2] == 0) continue;
                    long long ways = dp[i][g1][g2];
                    // ignore x
                    dp[i + 1][g1][g2] = (dp[i + 1][g1][g2] + ways) % mod;
                    // put x in 1
                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
                    dp[i + 1][ng1][g2] = (dp[i + 1][ng1][g2] + ways) % mod;
                    // put x in 2
                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
                    dp[i + 1][g1][ng2] = (dp[i + 1][g1][ng2] + ways) % mod;
                }
            }
        }
        long long ans = 0;
        for(int g = 1; g <= 200; g++) {
            ans = (ans + dp[n][g][g]) % mod;
        }
        return ans;
    }
};