class Solution {
public:
    bool dfs(int n, int k, string& ans, unordered_set<string>& visited) {
        if(visited.size() == pow(k, n)) return true;
        string suffix = ans.substr(ans.size() - (n - 1), n - 1);
        string nextNode = suffix + '0';
        for(int i = 0; i < k; i++) {
            nextNode[n - 1] = (i + '0');
            if(!visited.count(nextNode)) {
                visited.insert(nextNode);
                ans += (i + '0');
                if(dfs(n, k, ans, visited)) return true;
                visited.erase(nextNode);
                ans.pop_back();
            }
        }
        return false;
    }
    
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string ans = string(n, '0');
        visited.insert(ans);
        dfs(n, k, ans, visited);
        return ans;
    }
};