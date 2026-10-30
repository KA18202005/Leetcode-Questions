class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n == 1) return 0;
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        dist[0][1] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0 , 1});
        vector<int> min_c(n, k + 1);
        while(!pq.empty()) {
            auto[d, u, c] = pq.top();
            pq.pop();
            if(d > dist[u][c]) continue;
            if(u == n - 1) return d;
            if(c >= min_c[u]) continue;
            min_c[u] = c;
            for(const auto& it : adj[u]) {
                int v = it.first;
                int w = it.second;
                int new_c = (labels[u] == labels[v]) ? c + 1 : 1;
                if(new_c <= k) {
                    if(d + w <= dist[v][new_c]) {
                        dist[v][new_c] = d + w;
                        pq.push({d + w, v, new_c});
                    }
                }
            }
        }
        return -1;
    }
};