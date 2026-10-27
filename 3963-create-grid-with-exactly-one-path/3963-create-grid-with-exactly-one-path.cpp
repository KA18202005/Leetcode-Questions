class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < n; i++) {
            temp += '.';
        }
        ans.push_back(temp);
        temp = "";
        for(int j = 0; j < n - 1; j++) {
            temp += '#';
        }
        temp += '.';
        for(int i = 0; i < m - 1; i++) {
            ans.push_back(temp);
        }
        return ans;
    }
};