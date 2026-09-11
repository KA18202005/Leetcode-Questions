class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        int cntfresh = 0;
        queue<pair<pair<int,int>,int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1) cntfresh++;
            }
        }
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int tm = 0, cnt = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow < 0 || ncol < 0 || nrow >= n || ncol >= m) continue;
                if (grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    cnt++;
                }
            }
        }
        if (cnt != cntfresh) return -1;
        return tm;
    }
};