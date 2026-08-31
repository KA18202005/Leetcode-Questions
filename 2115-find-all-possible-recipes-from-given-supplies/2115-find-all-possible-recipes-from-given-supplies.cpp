class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, int> id;
        for(int i = 0; i < n; i++) {
            id[recipes[i]] = i;
        }
        unordered_map<string, vector<int>> graph;
        vector<int> need(n);
        for(int i = 0; i < n; i++) {
            need[i] = ingredients[i].size();
            for(string x : ingredients[i]) {
                graph[x].push_back(i);
            }
        }
        queue<string> q;
        for(string x : supplies) {
            q.push(x);
        }
        vector<string> ans;
        while(!q.empty()) {
            string x = q.front();
            q.pop();
            for(int recipe : graph[x]) {
                need[recipe]--;
                if(need[recipe] == 0) {
                    ans.push_back(recipes[recipe]);
                    q.push(recipes[recipe]);
                }
            }
        }
        return ans;
    }
};