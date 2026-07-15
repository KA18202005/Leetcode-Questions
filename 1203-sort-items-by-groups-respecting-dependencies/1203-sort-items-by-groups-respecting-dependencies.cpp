class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& graph, vector<int> indegree) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : graph[u]) {
                if (--indegree[v] == 0) q.push(v);
            }
        }
        return order;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) group[i] = m++;
        }
        vector<vector<int>> itemGraph(n);
        vector<int> itemIndegree(n, 0);
        vector<vector<int>> groupGraph(m);
        vector<int> groupIndegree(m, 0);
        for (int v = 0; v < n; v++) {
            for (int u : beforeItems[v]) {
                itemGraph[u].push_back(v);
                itemIndegree[v]++;
                if (group[u] != group[v]) {
                    groupGraph[group[u]].push_back(group[v]);
                    groupIndegree[group[v]]++;
                }
            }
        }
        vector<int> groupOrder = topoSort(groupGraph, groupIndegree);
        if (groupOrder.size() != m) return {};
        vector<int> itemOrder = topoSort(itemGraph, itemIndegree);
        if (itemOrder.size() != n) return {};
        unordered_map<int, vector<int>> groupItems;
        for (int item : itemOrder) groupItems[group[item]].push_back(item);
        vector<int> ans;
        for (int g : groupOrder) {
            for (int item : groupItems[g])
                ans.push_back(item);
        }
        return ans;
    }
};