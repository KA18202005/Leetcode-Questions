class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                dp[i][j] = 1 + dp[i + 1][j];
                for(int k = i + 1; k <= j; k++) {
                    if(s[i] == s[k]) {
                        int middle = 0;
                        if(k > i + 1) middle = dp[i + 1][k - 1];
                        dp[i][j] = min(dp[i][j], middle + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};