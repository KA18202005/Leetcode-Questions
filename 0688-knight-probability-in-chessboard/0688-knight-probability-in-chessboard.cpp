class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                dp[0][r][c] = 1.0;
            }
        }
        int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        for(int moves = 1; moves <= k; moves++) {
            for(int r = 0; r < n; r++) {
                for(int c = 0; c < n; c++) {
                    for(int d = 0; d < 8; d++) {
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            dp[moves][r][c] += dp[moves - 1][nr][nc] / 8.0;
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};