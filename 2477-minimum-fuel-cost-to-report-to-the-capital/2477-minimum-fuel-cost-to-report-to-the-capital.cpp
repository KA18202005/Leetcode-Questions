class Solution {
public:
    long long fuel = 0;
    int seats;

    long long dfs(int node, int parent, vector<vector<int>>& graph) {\
        long long people = 1;
        for(int child : graph[node]) {
            if(child == parent) continue;
            people += dfs(child, node, graph);
        }
        if(node != 0) {
            fuel += (people + seats - 1) / seats;
        }
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        this->seats = seats;
        int n = roads.size();
        vector<vector<int>> graph(n + 1);
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0, -1, graph);
        return fuel;
    }
};