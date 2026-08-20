class Solution {
public:
    int ans = 1;
    int dfs(int node, vector<vector<int>>& children, string& s) {
        int longest1 = 0;
        int longest2 = 0;
        for(int child : children[node]) {
            int len = dfs(child, children, s);
            if(s[child] == s[node]) continue;
            if(len > longest1) {
                longest2 = longest1;
                longest1 = len;
            }
            else if(len > longest2) longest2 = len;
        }
        ans = max(ans, longest1 + longest2 + 1);
        return longest1 + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for(int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        dfs(0, children, s);
        return ans;
    }
};