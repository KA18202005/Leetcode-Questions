class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); i++) {
            int people = group[i];
            int money = profit[i];
            for (int p = n; p >= people; p--) {
                for (int pr = minProfit; pr >= 0; pr--) {
                    int newProfit = min(minProfit, pr + money);
                    dp[p][newProfit] = (dp[p][newProfit] + dp[p - people][pr]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int p = 0; p <= n; p++) {
            ans = (ans + dp[p][minProfit]) % MOD;
        }
        return ans;
    }
};