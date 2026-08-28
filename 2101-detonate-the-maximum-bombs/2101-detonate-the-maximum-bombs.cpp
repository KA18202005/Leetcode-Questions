class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    int dfs(int u) {
        vis[u] = true;
        int cnt = 1;
        for (int v : graph[u]) {
            if (!vis[v]) cnt += dfs(v);
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& b) {
        int n = b.size();
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long dx = b[i][0] - b[j][0];
                long long dy = b[i][1] - b[j][1];
                if (dx * dx + dy * dy <= 1LL * b[i][2] * b[i][2]) graph[i].push_back(j);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vis.assign(n, false);
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};