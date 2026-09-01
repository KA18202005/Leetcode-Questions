class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    long long numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        sz.assign(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
        vector<vector<int>> graph(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        map<int, vector<int>> groups;
        for(int i = 0; i < n; i++) groups[vals[i]].push_back(i);
        long long ans = n;
        for(auto &[value, nodes] : groups) {
            for(int u : nodes) {
                for(int v : graph[u]) {
                    if(vals[v] <= value) unite(u, v);
                }
            }
            map<int, int> count;
            for(int u : nodes) count[find(u)]++;
            for(auto &[root, k] : count) {
                ans += 1LL * k * (k - 1) / 2;
            }
        }
        return ans;
    }
};