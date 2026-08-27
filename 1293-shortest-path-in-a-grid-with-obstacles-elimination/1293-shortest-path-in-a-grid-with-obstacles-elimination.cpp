class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int, int>> q;
        q.push({0, 0, 0, k});
        visited[0][0][k] = true;
        while(!q.empty()) {
            auto [steps, r, c, rem] = q.front();
            q.pop();
            if(r == m - 1 && c == n - 1) return steps;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                int newRem = rem;
                if(grid[nr][nc] == 1) {
                    if(newRem == 0) continue;
                    newRem--;
                }
                if(!visited[nr][nc][newRem]) {
                    visited[nr][nc][newRem] = true;
                    q.push({steps + 1, nr, nc, newRem});
                }
            }
        }
        return -1;
    }
};