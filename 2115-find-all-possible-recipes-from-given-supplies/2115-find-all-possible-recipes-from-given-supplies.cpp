class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> avail;
        for(string s : supplies) {
            avail.insert(s);
        }
        vector<string> ans;
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 0; i < recipes.size(); i++) {
                if(avail.count(recipes[i])) continue;
                bool possible = true;
                for(string x : ingredients[i]) {
                    if(!avail.count(x)) {
                        possible = false;
                        break;
                    }
                }
                if(possible) {
                    avail.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    flag = true;
                }
            }
        }
        return ans;
    }
};