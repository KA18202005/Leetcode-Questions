class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(1024, false)));
        queue<tuple<int,int,int>> q;
        q.push({0, 0, grid[0][0]});
        vis[0][0][grid[0][0]] = true;
        int dr[2] = {0, 1};
        int dc[2] = {1, 0};
        int ans = INT_MAX;
        while (!q.empty()) {
            auto [i, j, x] = q.front();
            q.pop();
            if (i == n - 1 && j == m - 1) {
                ans = min(ans, x);
                continue;
            }
            for (int d = 0; d < 2; d++) {
                int ni = i + dr[d];
                int nj = j + dc[d];
                if (ni < n && nj < m) {
                    int nx = x ^ grid[ni][nj];
                    if (!vis[ni][nj][nx]) {
                        vis[ni][nj][nx] = true;
                        q.push({ni, nj, nx});
                    }
                }
            }
        }
        return ans;
    }
};