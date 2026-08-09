class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suf(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + piles[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {
                for (int X = 1; X <= 2 * M && i + X <= n; X++) {
                    int nextM = max(M, X);
                    int opponent = 0;
                    if (i + X < n) opponent = dp[i + X][nextM];
                    int current = suf[i] - opponent;
                    dp[i][M] = max(dp[i][M], current);
                }
            }
        }
        return dp[0][1];
    }
};