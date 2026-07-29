class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int dfs(int row, int col, vector<vector<int>>& matrix) {
        if (dp[row][col] != -1) return dp[row][col];
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && matrix[nrow][ncol] > matrix[row][col]) {
                ans = max(ans, 1 + dfs(nrow, ncol, matrix));
            }
        }
        return dp[row][col] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};