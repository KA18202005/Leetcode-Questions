class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inout;
        for (const auto& pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            inout[pair[0]]++;
            inout[pair[1]]--;
        }
        int startNode = pairs[0][0];
        for (const auto& [node, degree] : inout) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }
        vector<int> path;
        stack<int> st;
        st.push(startNode);
        while (!st.empty()) {
            auto& neigh = adj[st.top()];
            if (neigh.empty()) {
                path.push_back(st.top());
                st.pop();
            }
            else {
                int nextNode = neigh.back();
                st.push(nextNode);
                neigh.pop_back();
            }
        }
        vector<vector<int>> arr;
        int n = path.size();
        arr.reserve(n - 1);
        for (int i = n - 1; i > 0; --i) {
            arr.push_back({path[i], path[i-1]});
        }
        return arr;
    }
};