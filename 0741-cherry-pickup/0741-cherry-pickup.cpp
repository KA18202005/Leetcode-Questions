class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n - 1, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][0] = grid[0][0];
        for (int steps = 1; steps <= 2 * n - 2; steps++) {
            for (int r1 = 0; r1 < n; r1++) {
                int c1 = steps - r1;
                if (c1 < 0 || c1 >= n) continue;
                for (int r2 = 0; r2 < n; r2++) {
                    int c2 = steps - r2;
                    if (c2 < 0 || c2 >= n) continue;
                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) continue;
                    int best = -1;
                    if (r1 > 0 && r2 > 0) {
                        best = max(best, dp[steps - 1][r1 - 1][r2 - 1]);
                    }
                    if (r1 > 0) {
                        best = max(best, dp[steps - 1][r1 - 1][r2]);
                    }
                    if (r2 > 0) {
                        best = max(best, dp[steps - 1][r1][r2 - 1]);
                    }
                    best = max(best, dp[steps - 1][r1][r2]);
                    if (best == -1) continue;
                    int cherries = best;
                    if (r1 == r2) {
                        cherries += grid[r1][c1];
                    }
                    else {
                        cherries += grid[r1][c1];
                        cherries += grid[r2][c2];
                    }
                    dp[steps][r1][r2] = cherries;
                }
            }
        }
        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};