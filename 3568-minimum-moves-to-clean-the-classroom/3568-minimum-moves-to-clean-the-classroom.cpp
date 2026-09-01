class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        vector<vector<int>> lmap(m, vector<int>(n, -1));
        int sx = -1, sy = -1;
        int lcnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    lmap[i][j] = lcnt++;
                }
            }
        }
        if (lcnt == 0) return 0;
        int tmask = (1 << lcnt) - 1;
        queue<tuple<int, int, int, int, int>> q;
        q.push({sx, sy, energy, 0, 0});
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy + 1, vector<bool>(1 << lcnt, false))));
        vis[sx][sy][energy][0] = true;
        int dir[5] = {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            auto [r, c, e, mask, steps] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int ne = e - 1;
                    int nmask = mask;
                    if(classroom[nr][nc] == 'L') nmask |= (1 << lmap[nr][nc]);
                    if(nmask == tmask) return steps + 1;
                    if(classroom[nr][nc] == 'R') ne = energy;
                    if (ne == 0 && classroom[nr][nc] != 'R') continue;
                    if(!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};