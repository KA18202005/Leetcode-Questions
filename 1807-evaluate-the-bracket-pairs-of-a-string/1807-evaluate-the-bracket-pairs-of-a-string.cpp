class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                string d = "";
                i++;
                while(s[i] != ')') {
                    d += s[i];
                    i++;
                }
                if(mpp.find(d) != mpp.end()) {
                    ans += mpp[d];
                }
                else ans += '?';
            }
            else ans += s[i];
        }
        return ans;
    }
};