class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int len = m + n - 1;
        if (len % 2 != 0 || grid[0][0] != '(' || grid[m - 1][n - 1] != ')') {
            return false;
        }
        vector<bitset<100>> dp(n);
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                bitset<100> rb;
                if (row > 0) rb |= dp[col];
                if (col > 0) rb |= dp[col - 1];
                if (row == 0 && col == 0) rb.set(0);
                dp[col] = grid[row][col] == '(' ? (rb << 1) : (rb >> 1);
            }
        }
        return dp[n - 1].test(0);
    }
};