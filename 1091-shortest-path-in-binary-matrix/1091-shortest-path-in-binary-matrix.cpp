class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n-1] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int delrow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delcol[9] = {-1, 0, 1, 1, 1, 0, -1, -1};
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = 1;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int d = dis[row][col];
            for(int i = 0; i < 8; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                    if(d + 1 < dis[nrow][ncol]) {
                        dis[nrow][ncol] = d + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        if(dis[n-1][n-1] == 1e9) return -1;
        return dis[n-1][n-1];
    }
};