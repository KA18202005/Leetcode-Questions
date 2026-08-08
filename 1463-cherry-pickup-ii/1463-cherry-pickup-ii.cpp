class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, INT_MIN)));
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                for(int k = 0; k < cols; k++) {
                    int best = INT_MIN;
                    for(int dj = -1; dj <= 1; dj++) {
                        for(int dk = -1; dk <= 1; dk++) {
                            int prevJ = j + dj;
                            int prevK = k + dk;
                            if(prevJ >= 0 && prevJ < cols && prevK >= 0 && prevK < cols) {
                                best = max(best, dp[i - 1][prevJ][prevK]);
                            }
                        }
                    }
                    if(j == k) dp[i][j][k] = best + grid[i][j];    
                    else dp[i][j][k] = best + grid[i][j] + grid[i][k];
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < cols; j++) {
            for(int k = 0; k < cols; k++) {
                ans = max(ans, dp[rows - 1][j][k]);
            }
        }

        return ans;
    }
};