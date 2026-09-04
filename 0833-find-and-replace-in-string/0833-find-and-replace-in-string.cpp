class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = indices.size();
        vector<string> rep(s.size());
        vector<int> len(s.size(), 0);
        for(int i = 0; i < n; i++) {
            int idx = indices[i];
            if(s.substr(idx, sources[i].size()) == sources[i]) {
                rep[idx] = targets[i];
                len[idx] = sources[i].size();
            }
        }
        string ans = "";
        for(int i = 0; i < s.size(); ) {
            if(len[i] > 0) {
                ans += rep[i];
                i += len[i];
            }
            else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};