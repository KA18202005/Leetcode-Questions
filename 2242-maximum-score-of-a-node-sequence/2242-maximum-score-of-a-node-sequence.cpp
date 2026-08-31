class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> graph(n);
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 0; i < n; i++) {
            sort(graph[i].begin(), graph[i].end(), [&](int a, int b) {
                return scores[a] > scores[b];
            });
            if(graph[i].size() > 3) graph[i].resize(3);
        }
        int ans = -1;
        for(auto e : edges) {
            int b = e[0];
            int c = e[1];
            for(int a : graph[b]) {
                for(int d : graph[c]) {
                    if(a == c || d == b || a == d) continue;
                    int sum = scores[a] + scores[b] + scores[c] + scores[d];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};